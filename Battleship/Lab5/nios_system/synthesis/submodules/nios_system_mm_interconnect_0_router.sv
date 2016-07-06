// (C) 2001-2015 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.



// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/15.1/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#1 $
// $Revision: #1 $
// $Date: 2015/08/09 $
// $Author: swbranch $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module nios_system_mm_interconnect_0_router_default_decode
  #(
     parameter DEFAULT_CHANNEL = 2,
               DEFAULT_WR_CHANNEL = -1,
               DEFAULT_RD_CHANNEL = -1,
               DEFAULT_DESTID = 13 
   )
  (output [84 - 80 : 0] default_destination_id,
   output [32-1 : 0] default_wr_channel,
   output [32-1 : 0] default_rd_channel,
   output [32-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[84 - 80 : 0];

  generate
    if (DEFAULT_CHANNEL == -1) begin : no_default_channel_assignment
      assign default_src_channel = '0;
    end
    else begin : default_channel_assignment
      assign default_src_channel = 32'b1 << DEFAULT_CHANNEL;
    end
  endgenerate

  generate
    if (DEFAULT_RD_CHANNEL == -1) begin : no_default_rw_channel_assignment
      assign default_wr_channel = '0;
      assign default_rd_channel = '0;
    end
    else begin : default_rw_channel_assignment
      assign default_wr_channel = 32'b1 << DEFAULT_WR_CHANNEL;
      assign default_rd_channel = 32'b1 << DEFAULT_RD_CHANNEL;
    end
  endgenerate

endmodule


module nios_system_mm_interconnect_0_router
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [98-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [98-1    : 0] src_data,
    output reg [32-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 53;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 84;
    localparam PKT_DEST_ID_L = 80;
    localparam PKT_PROTECTION_H = 88;
    localparam PKT_PROTECTION_L = 86;
    localparam ST_DATA_W = 98;
    localparam ST_CHANNEL_W = 32;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 56;
    localparam PKT_TRANS_READ  = 57;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;



    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h20000 - 64'h10000); 
    localparam PAD1 = log2ceil(64'h21000 - 64'h20800); 
    localparam PAD2 = log2ceil(64'h21010 - 64'h21000); 
    localparam PAD3 = log2ceil(64'h21020 - 64'h21010); 
    localparam PAD4 = log2ceil(64'h21030 - 64'h21020); 
    localparam PAD5 = log2ceil(64'h21040 - 64'h21030); 
    localparam PAD6 = log2ceil(64'h21050 - 64'h21040); 
    localparam PAD7 = log2ceil(64'h21060 - 64'h21050); 
    localparam PAD8 = log2ceil(64'h21070 - 64'h21060); 
    localparam PAD9 = log2ceil(64'h21080 - 64'h21070); 
    localparam PAD10 = log2ceil(64'h21090 - 64'h21080); 
    localparam PAD11 = log2ceil(64'h210a0 - 64'h21090); 
    localparam PAD12 = log2ceil(64'h210b0 - 64'h210a0); 
    localparam PAD13 = log2ceil(64'h210c0 - 64'h210b0); 
    localparam PAD14 = log2ceil(64'h210d0 - 64'h210c0); 
    localparam PAD15 = log2ceil(64'h210e0 - 64'h210d0); 
    localparam PAD16 = log2ceil(64'h210f0 - 64'h210e0); 
    localparam PAD17 = log2ceil(64'h21100 - 64'h210f0); 
    localparam PAD18 = log2ceil(64'h21110 - 64'h21100); 
    localparam PAD19 = log2ceil(64'h21120 - 64'h21110); 
    localparam PAD20 = log2ceil(64'h21130 - 64'h21120); 
    localparam PAD21 = log2ceil(64'h21140 - 64'h21130); 
    localparam PAD22 = log2ceil(64'h21150 - 64'h21140); 
    localparam PAD23 = log2ceil(64'h21160 - 64'h21150); 
    localparam PAD24 = log2ceil(64'h21170 - 64'h21160); 
    localparam PAD25 = log2ceil(64'h21180 - 64'h21170); 
    localparam PAD26 = log2ceil(64'h21190 - 64'h21180); 
    localparam PAD27 = log2ceil(64'h211a0 - 64'h21190); 
    localparam PAD28 = log2ceil(64'h211b0 - 64'h211a0); 
    localparam PAD29 = log2ceil(64'h211c0 - 64'h211b0); 
    localparam PAD30 = log2ceil(64'h211d0 - 64'h211c0); 
    localparam PAD31 = log2ceil(64'h211d8 - 64'h211d0); 
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h211d8;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;

    localparam RG = RANGE_ADDR_WIDTH-1;
    localparam REAL_ADDRESS_RANGE = OPTIMIZED_ADDR_H - PKT_ADDR_L;

      reg [PKT_ADDR_W-1 : 0] address;
      always @* begin
        address = {PKT_ADDR_W{1'b0}};
        address [REAL_ADDRESS_RANGE:0] = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];
      end   

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;
    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [32-1 : 0] default_src_channel;




    // -------------------------------------------------------
    // Write and read transaction signals
    // -------------------------------------------------------
    wire read_transaction;
    assign read_transaction  = sink_data[PKT_TRANS_READ];


    nios_system_mm_interconnect_0_router_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_wr_channel   (),
      .default_rd_channel   (),
      .default_src_channel  (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;
        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;

        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

    // ( 0x10000 .. 0x20000 )
    if ( {address[RG:PAD0],{PAD0{1'b0}}} == 18'h10000   ) begin
            src_channel = 32'b00000000000000000000000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 13;
    end

    // ( 0x20800 .. 0x21000 )
    if ( {address[RG:PAD1],{PAD1{1'b0}}} == 18'h20800   ) begin
            src_channel = 32'b00000000000000000000000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 11;
    end

    // ( 0x21000 .. 0x21010 )
    if ( {address[RG:PAD2],{PAD2{1'b0}}} == 18'h21000   ) begin
            src_channel = 32'b10000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 31;
    end

    // ( 0x21010 .. 0x21020 )
    if ( {address[RG:PAD3],{PAD3{1'b0}}} == 18'h21010   ) begin
            src_channel = 32'b01000000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 30;
    end

    // ( 0x21020 .. 0x21030 )
    if ( {address[RG:PAD4],{PAD4{1'b0}}} == 18'h21020   ) begin
            src_channel = 32'b00100000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 29;
    end

    // ( 0x21030 .. 0x21040 )
    if ( {address[RG:PAD5],{PAD5{1'b0}}} == 18'h21030   ) begin
            src_channel = 32'b00010000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 28;
    end

    // ( 0x21040 .. 0x21050 )
    if ( {address[RG:PAD6],{PAD6{1'b0}}} == 18'h21040   ) begin
            src_channel = 32'b00001000000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 27;
    end

    // ( 0x21050 .. 0x21060 )
    if ( {address[RG:PAD7],{PAD7{1'b0}}} == 18'h21050   ) begin
            src_channel = 32'b00000100000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 26;
    end

    // ( 0x21060 .. 0x21070 )
    if ( {address[RG:PAD8],{PAD8{1'b0}}} == 18'h21060   ) begin
            src_channel = 32'b00000010000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 25;
    end

    // ( 0x21070 .. 0x21080 )
    if ( {address[RG:PAD9],{PAD9{1'b0}}} == 18'h21070   ) begin
            src_channel = 32'b00000001000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 24;
    end

    // ( 0x21080 .. 0x21090 )
    if ( {address[RG:PAD10],{PAD10{1'b0}}} == 18'h21080   ) begin
            src_channel = 32'b00000000100000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 21;
    end

    // ( 0x21090 .. 0x210a0 )
    if ( {address[RG:PAD11],{PAD11{1'b0}}} == 18'h21090   ) begin
            src_channel = 32'b00000000010000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 16;
    end

    // ( 0x210a0 .. 0x210b0 )
    if ( {address[RG:PAD12],{PAD12{1'b0}}} == 18'h210a0   ) begin
            src_channel = 32'b00000000001000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 23;
    end

    // ( 0x210b0 .. 0x210c0 )
    if ( {address[RG:PAD13],{PAD13{1'b0}}} == 18'h210b0   ) begin
            src_channel = 32'b00000000000100000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 22;
    end

    // ( 0x210c0 .. 0x210d0 )
    if ( {address[RG:PAD14],{PAD14{1'b0}}} == 18'h210c0   ) begin
            src_channel = 32'b00000000000010000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 20;
    end

    // ( 0x210d0 .. 0x210e0 )
    if ( {address[RG:PAD15],{PAD15{1'b0}}} == 18'h210d0   ) begin
            src_channel = 32'b00000000000001000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
    end

    // ( 0x210e0 .. 0x210f0 )
    if ( {address[RG:PAD16],{PAD16{1'b0}}} == 18'h210e0   ) begin
            src_channel = 32'b00000000000000100000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
    end

    // ( 0x210f0 .. 0x21100 )
    if ( {address[RG:PAD17],{PAD17{1'b0}}} == 18'h210f0   ) begin
            src_channel = 32'b00000000000000010000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 17;
    end

    // ( 0x21100 .. 0x21110 )
    if ( {address[RG:PAD18],{PAD18{1'b0}}} == 18'h21100   ) begin
            src_channel = 32'b00000000000000001000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 8;
    end

    // ( 0x21110 .. 0x21120 )
    if ( {address[RG:PAD19],{PAD19{1'b0}}} == 18'h21110   ) begin
            src_channel = 32'b00000000000000000100000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 1;
    end

    // ( 0x21120 .. 0x21130 )
    if ( {address[RG:PAD20],{PAD20{1'b0}}} == 18'h21120   ) begin
            src_channel = 32'b00000000000000000010000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 5;
    end

    // ( 0x21130 .. 0x21140 )
    if ( {address[RG:PAD21],{PAD21{1'b0}}} == 18'h21130   ) begin
            src_channel = 32'b00000000000000000001000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 14;
    end

    // ( 0x21140 .. 0x21150 )
    if ( {address[RG:PAD22],{PAD22{1'b0}}} == 18'h21140   ) begin
            src_channel = 32'b00000000000000000000100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 12;
    end

    // ( 0x21150 .. 0x21160 )
    if ( {address[RG:PAD23],{PAD23{1'b0}}} == 18'h21150   ) begin
            src_channel = 32'b00000000000000000000010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 2;
    end

    // ( 0x21160 .. 0x21170 )
    if ( {address[RG:PAD24],{PAD24{1'b0}}} == 18'h21160  && read_transaction  ) begin
            src_channel = 32'b00000000000000000000001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 3;
    end

    // ( 0x21170 .. 0x21180 )
    if ( {address[RG:PAD25],{PAD25{1'b0}}} == 18'h21170  && read_transaction  ) begin
            src_channel = 32'b00000000000000000000000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 6;
    end

    // ( 0x21180 .. 0x21190 )
    if ( {address[RG:PAD26],{PAD26{1'b0}}} == 18'h21180   ) begin
            src_channel = 32'b00000000000000000000000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 10;
    end

    // ( 0x21190 .. 0x211a0 )
    if ( {address[RG:PAD27],{PAD27{1'b0}}} == 18'h21190  && read_transaction  ) begin
            src_channel = 32'b00000000000000000000000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 4;
    end

    // ( 0x211a0 .. 0x211b0 )
    if ( {address[RG:PAD28],{PAD28{1'b0}}} == 18'h211a0   ) begin
            src_channel = 32'b00000000000000000000000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 15;
    end

    // ( 0x211b0 .. 0x211c0 )
    if ( {address[RG:PAD29],{PAD29{1'b0}}} == 18'h211b0   ) begin
            src_channel = 32'b00000000000000000000000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 7;
    end

    // ( 0x211c0 .. 0x211d0 )
    if ( {address[RG:PAD30],{PAD30{1'b0}}} == 18'h211c0   ) begin
            src_channel = 32'b00000000000000000000000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 0;
    end

    // ( 0x211d0 .. 0x211d8 )
    if ( {address[RG:PAD31],{PAD31{1'b0}}} == 18'h211d0   ) begin
            src_channel = 32'b00000000000000000000000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 9;
    end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule


