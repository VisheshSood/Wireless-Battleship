	component nios_system is
		port (
			address_export    : out   std_logic_vector(10 downto 0);                    -- export
			char_read_export  : out   std_logic;                                        -- export
			char_recv_export  : in    std_logic                     := 'X';             -- export
			char_sent_export  : in    std_logic                     := 'X';             -- export
			chipreset_export  : out   std_logic;                                        -- export
			clk_clk           : in    std_logic                     := 'X';             -- clk
			data_export       : inout std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			data_in_export    : in    std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			data_out_export   : out   std_logic_vector(7 downto 0);                     -- export
			leds_export       : out   std_logic_vector(7 downto 0);                     -- export
			load_export       : out   std_logic;                                        -- export
			notouten_export   : out   std_logic;                                        -- export
			readnwrite_export : out   std_logic;                                        -- export
			reset_reset_n     : in    std_logic                     := 'X';             -- reset_n
			trans_en_export   : out   std_logic;                                        -- export
			yourboard0_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard1_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard2_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard3_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard4_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard5_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard6_export : out   std_logic_vector(7 downto 0);                     -- export
			yourboard7_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots0_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots1_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots2_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots3_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots4_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots5_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots6_export : out   std_logic_vector(7 downto 0);                     -- export
			yourshots7_export : out   std_logic_vector(7 downto 0)                      -- export
		);
	end component nios_system;

	u0 : component nios_system
		port map (
			address_export    => CONNECTED_TO_address_export,    --    address.export
			char_read_export  => CONNECTED_TO_char_read_export,  --  char_read.export
			char_recv_export  => CONNECTED_TO_char_recv_export,  --  char_recv.export
			char_sent_export  => CONNECTED_TO_char_sent_export,  --  char_sent.export
			chipreset_export  => CONNECTED_TO_chipreset_export,  --  chipreset.export
			clk_clk           => CONNECTED_TO_clk_clk,           --        clk.clk
			data_export       => CONNECTED_TO_data_export,       --       data.export
			data_in_export    => CONNECTED_TO_data_in_export,    --    data_in.export
			data_out_export   => CONNECTED_TO_data_out_export,   --   data_out.export
			leds_export       => CONNECTED_TO_leds_export,       --       leds.export
			load_export       => CONNECTED_TO_load_export,       --       load.export
			notouten_export   => CONNECTED_TO_notouten_export,   --   notouten.export
			readnwrite_export => CONNECTED_TO_readnwrite_export, -- readnwrite.export
			reset_reset_n     => CONNECTED_TO_reset_reset_n,     --      reset.reset_n
			trans_en_export   => CONNECTED_TO_trans_en_export,   --   trans_en.export
			yourboard0_export => CONNECTED_TO_yourboard0_export, -- yourboard0.export
			yourboard1_export => CONNECTED_TO_yourboard1_export, -- yourboard1.export
			yourboard2_export => CONNECTED_TO_yourboard2_export, -- yourboard2.export
			yourboard3_export => CONNECTED_TO_yourboard3_export, -- yourboard3.export
			yourboard4_export => CONNECTED_TO_yourboard4_export, -- yourboard4.export
			yourboard5_export => CONNECTED_TO_yourboard5_export, -- yourboard5.export
			yourboard6_export => CONNECTED_TO_yourboard6_export, -- yourboard6.export
			yourboard7_export => CONNECTED_TO_yourboard7_export, -- yourboard7.export
			yourshots0_export => CONNECTED_TO_yourshots0_export, -- yourshots0.export
			yourshots1_export => CONNECTED_TO_yourshots1_export, -- yourshots1.export
			yourshots2_export => CONNECTED_TO_yourshots2_export, -- yourshots2.export
			yourshots3_export => CONNECTED_TO_yourshots3_export, -- yourshots3.export
			yourshots4_export => CONNECTED_TO_yourshots4_export, -- yourshots4.export
			yourshots5_export => CONNECTED_TO_yourshots5_export, -- yourshots5.export
			yourshots6_export => CONNECTED_TO_yourshots6_export, -- yourshots6.export
			yourshots7_export => CONNECTED_TO_yourshots7_export  -- yourshots7.export
		);

