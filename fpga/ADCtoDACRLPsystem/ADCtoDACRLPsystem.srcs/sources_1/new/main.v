`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 20.02.2025 23:18:55
// Design Name: 
// Module Name: main
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module main (
    input wire clk,            // Тактовый сигнал
    input wire reset,          // Сброс
    input wire [15:0] adc_data, // Входные данные ADC (16 бит)
    output reg [15:0] dac_data, // Выходные данные DAC (16 бит)
    output reg [15:0] crc_out   // Контрольная сумма CRC-16
);

// Контрольная сумма CRC-16-CCITT
function [15:0] calculate_crc;
    input [15:0] data;
    reg [15:0] crc;
    integer i;
begin
    crc = 16'hFFFF;
    for (i = 0; i < 16; i = i + 1) begin
        if ((crc[15] ^ data[i]) == 1) 
            crc = (crc << 1) ^ 16'h8005;
        else 
            crc = (crc << 1);
    end
    calculate_crc = crc;
end
endfunction

// Основная логика
always @(posedge clk or posedge reset) begin
    if (reset) begin
        dac_data <= 16'd0;
        crc_out <= 16'd0;
    end else begin
        dac_data <= adc_data;               // Передаем сигнал на ЦАП
        crc_out <= calculate_crc(adc_data); // Вычисляем CRC
    end
end

endmodule