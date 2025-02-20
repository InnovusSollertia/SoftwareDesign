`timescale 1ns / 1ps

module test;
    reg clk;
    reg reset;
    reg [15:0] adc_data;
    wire [15:0] dac_data;
    wire [15:0] crc_out;

    // Подключаем тестируемый модуль
    radar_processing uut (
        .clk(clk),
        .reset(reset),
        .adc_data(adc_data),
        .dac_data(dac_data),
        .crc_out(crc_out)
    );

    // Генерация тактового сигнала
    always #5 clk = ~clk;

    initial begin
        // Инициализация
        clk = 0;
        reset = 1;
        adc_data = 16'h0000;
        #10 reset = 0;

        // Передача тестовых данных
        #10 adc_data = 16'h1234;
        #10 adc_data = 16'hABCD;
        #10 adc_data = 16'hFFFF;
        #10 adc_data = 16'h0001;

        // Завершение симуляции
        #50 $stop;
    end
endmodule