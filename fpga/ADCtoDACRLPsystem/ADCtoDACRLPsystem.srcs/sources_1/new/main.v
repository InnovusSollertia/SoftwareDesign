module radar_processing_tb;
    reg clk;
    reg rst;
    reg [9:0] x_data, y_data, z_data;
    wire [31:0] processed_data;
    wire [255:0] encrypted_data_aes;
    wire [255:0] encrypted_data_rsa;
    wire [31:0] checksum;
    wire [127:0] gpg_key_address;

    // Подключение тестируемого модуля
    radar_processing uut (
        .clk(clk),
        .rst(rst),
        .x_data(x_data),
        .y_data(y_data),
        .z_data(z_data),
        .processed_data(processed_data),
        .encrypted_data_aes(encrypted_data_aes),
        .encrypted_data_rsa(encrypted_data_rsa),
        .checksum(checksum),
        .gpg_key_address(gpg_key_address)
    );

    // Генерация тактового сигнала
    always #5 clk = ~clk;

    initial begin
        $dumpfile("radar_processing_tb.vcd");
        $dumpvars(0, radar_processing_tb);
        
        // Инициализация сигналов
        clk = 0;
        rst = 1;
        x_data = 10'd0;
        y_data = 10'd0;
        z_data = 10'd0;
        
        #10 rst = 0;
        
        // Тестовые данные с задержкой
        #10 x_data = 10'd512; y_data = 10'd256; z_data = 10'd128;
        #10 x_data = 10'd600; y_data = 10'd300; z_data = 10'd150;
        #10 x_data = 10'd700; y_data = 10'd400; z_data = 10'd200;
        #10 x_data = 10'd800; y_data = 10'd500; z_data = 10'd250;
        #10 x_data = 10'd900; y_data = 10'd600; z_data = 10'd300;
        
        // Ожидание завершения тестов
        #50;
        
        // Завершение симуляции
        $finish;
    end
endmodule