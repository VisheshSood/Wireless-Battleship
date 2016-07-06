module clock16x(CLOCK_50, clk);
    input CLOCK_50;
    output reg clk = 0;
    reg [7:0] count = 8'b0;

    always @(posedge CLOCK_50) begin
        if (count == 8'b10100010) begin
            count <= 8'b0;
            clk <= ~clk;
        end
        else begin
            count <= count + 1'b1;
				clk <= clk;
        end
    end
endmodule