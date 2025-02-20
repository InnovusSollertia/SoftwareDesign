#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define NUM_SAMPLES 1000
#define CRC_POLY 0x8005

// Прототипы функций
uint16_t calculate_crc(uint16_t *data, int num_samples);
void calculate_sha256(uint16_t *data, int num_samples, uint8_t *hash_output);
void generate_analog_signal(double *signal, int num_samples);
void digitize_signal(double *analog_signal, uint16_t *digital_signal, int num_samples);
void write_to_eeprom(uint32_t addr, void *data, size_t size);
void read_from_eeprom(uint32_t addr, void *data, size_t size);

// Глобальный массив EEPROM для тестирования
uint8_t eeprom_mock[512];

// Эмуляция EEPROM
void write_to_eeprom(uint32_t addr, void *data, size_t size) {
    memcpy(&eeprom_mock[addr], data, size);
}

void read_from_eeprom(uint32_t addr, void *data, size_t size) {
    memcpy(data, &eeprom_mock[addr], size);
}

// Основная тестовая функция
void test_algorithm() {
    printf("Running testbench...\n");

    double analog_signal[NUM_SAMPLES];
    uint16_t digital_signal[NUM_SAMPLES];
    uint16_t crc_adc, crc_dac;
    uint8_t sha_adc[32], sha_dac[32];

    generate_analog_signal(analog_signal, NUM_SAMPLES);
    digitize_signal(analog_signal, digital_signal, NUM_SAMPLES);

    crc_adc = calculate_crc(digital_signal, NUM_SAMPLES);
    calculate_sha256(digital_signal, NUM_SAMPLES, sha_adc);

    write_to_eeprom(0x0000, &crc_adc, sizeof(crc_adc));
    write_to_eeprom(0x0020, sha_adc, 32);

    uint16_t dac_signal[NUM_SAMPLES];
    memcpy(dac_signal, digital_signal, sizeof(digital_signal));

    crc_dac = calculate_crc(dac_signal, NUM_SAMPLES);
    calculate_sha256(dac_signal, NUM_SAMPLES, sha_dac);

    write_to_eeprom(0x0100, &crc_dac, sizeof(crc_dac));
    write_to_eeprom(0x0120, sha_dac, 32);

    uint16_t crc_adc_read, crc_dac_read;
    uint8_t sha_adc_read[32], sha_dac_read[32];

    read_from_eeprom(0x0000, &crc_adc_read, sizeof(crc_adc_read));
    read_from_eeprom(0x0020, sha_adc_read, 32);
    read_from_eeprom(0x0100, &crc_dac_read, sizeof(crc_dac_read));
    read_from_eeprom(0x0120, sha_dac_read, 32);

    assert(crc_adc == crc_dac);
    assert(memcmp(sha_adc, sha_dac, 32) == 0);

    printf("TEST PASSED: Data integrity verified!\n");
}

int main() {
    test_algorithm();
    return 0;
}
