#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SAMPLE_RATE 10e9
#define NUM_SAMPLES 1000
#define PI 3.14159265359
#define CRC_POLY 0x8005

// Структура координат цели
typedef struct {
    double x;
    double y;
    double z;
} TargetCoordinates;

// CRC-16
uint16_t calculate_crc(uint16_t *data, int num_samples) {
    uint16_t crc = 0;
    for (int i = 0; i < num_samples; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            crc = (crc & 0x8000) ? (crc << 1) ^ CRC_POLY : crc << 1;
        }
    }
    return crc;
}

// Генерация сигнала
void generate_analog_signal(double *signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        signal[i] = sin(2 * PI * 1e6 * i / SAMPLE_RATE) + ((rand() % 100) / 500.0);
    }
}

// Оцифровка (ADC)
void digitize_signal(double *analog_signal, uint16_t *digital_signal, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        digital_signal[i] = (uint16_t)((analog_signal[i] + 1.0) * 32767);
    }
}

// Вычисление координат
TargetCoordinates process_radar_data(uint16_t *digital_signal, int num_samples) {
    TargetCoordinates target = {0, 0, 0};
    for (int i = 0; i < num_samples; i++) {
        target.x += digital_signal[i] * 0.001;
        target.y += digital_signal[i] * 0.002;
        target.z += digital_signal[i] * 0.003;
    }
    target.x /= num_samples;
    target.y /= num_samples;
    target.z /= num_samples;
    return target;
}

int main() {
    printf("Initializing system...\n");
    srand(time(NULL));

    double analog_signal[NUM_SAMPLES];
    uint16_t digital_signal[NUM_SAMPLES];
    uint16_t crc_adc, crc_dac;

    generate_analog_signal(analog_signal, NUM_SAMPLES);
    digitize_signal(analog_signal, digital_signal, NUM_SAMPLES);

    crc_adc = calculate_crc(digital_signal, NUM_SAMPLES);

    uint16_t dac_signal[NUM_SAMPLES];
    memcpy(dac_signal, digital_signal, sizeof(digital_signal));

    crc_dac = calculate_crc(dac_signal, NUM_SAMPLES);

    if (crc_adc == crc_dac) {
        printf("Data integrity verified. CRC: 0x%X\n", crc_adc);
    } else {
        printf("Data mismatch! CRC ADC: 0x%X, CRC DAC: 0x%X\n", crc_adc, crc_dac);
    }

    TargetCoordinates target = process_radar_data(digital_signal, NUM_SAMPLES);
    printf("Target Coordinates: X = %.2f, Y = %.2f, Z = %.2f\n", target.x, target.y, target.z);

    return 0;
}
