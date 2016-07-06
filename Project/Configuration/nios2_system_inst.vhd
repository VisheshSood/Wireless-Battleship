	component nios2_system is
		port (
			address_pio_external_connection_export        : out std_logic_vector(10 downto 0);                    -- export
			charrcvd_pio_external_connection_export       : in  std_logic                     := 'X';             -- export
			charsent_pio_external_connection_export       : in  std_logic                     := 'X';             -- export
			chipselect_pio_external_connection_export     : out std_logic;                                        -- export
			clk_clk                                       : in  std_logic                     := 'X';             -- clk
			datain_pio_external_connection_export         : in  std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			dataout_pio_external_connection_export        : out std_logic_vector(7 downto 0);                     -- export
			enable_pio_external_connection_export         : out std_logic;                                        -- export
			led_pio_external_connection_export            : out std_logic_vector(7 downto 0);                     -- export
			load_pio_external_connection_export           : out std_logic;                                        -- export
			readnwrite_pio_external_connection_export     : out std_logic;                                        -- export
			receive_pio_external_connection_export        : in  std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			reset_reset_n                                 : in  std_logic                     := 'X';             -- reset_n
			switch_pio_external_connection_export         : in  std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			transmit_pio_external_connection_export       : out std_logic_vector(7 downto 0);                     -- export
			transmitenable_pio_external_connection_export : out std_logic                                         -- export
		);
	end component nios2_system;

	u0 : component nios2_system
		port map (
			address_pio_external_connection_export        => CONNECTED_TO_address_pio_external_connection_export,        --        address_pio_external_connection.export
			charrcvd_pio_external_connection_export       => CONNECTED_TO_charrcvd_pio_external_connection_export,       --       charrcvd_pio_external_connection.export
			charsent_pio_external_connection_export       => CONNECTED_TO_charsent_pio_external_connection_export,       --       charsent_pio_external_connection.export
			chipselect_pio_external_connection_export     => CONNECTED_TO_chipselect_pio_external_connection_export,     --     chipselect_pio_external_connection.export
			clk_clk                                       => CONNECTED_TO_clk_clk,                                       --                                    clk.clk
			datain_pio_external_connection_export         => CONNECTED_TO_datain_pio_external_connection_export,         --         datain_pio_external_connection.export
			dataout_pio_external_connection_export        => CONNECTED_TO_dataout_pio_external_connection_export,        --        dataout_pio_external_connection.export
			enable_pio_external_connection_export         => CONNECTED_TO_enable_pio_external_connection_export,         --         enable_pio_external_connection.export
			led_pio_external_connection_export            => CONNECTED_TO_led_pio_external_connection_export,            --            led_pio_external_connection.export
			load_pio_external_connection_export           => CONNECTED_TO_load_pio_external_connection_export,           --           load_pio_external_connection.export
			readnwrite_pio_external_connection_export     => CONNECTED_TO_readnwrite_pio_external_connection_export,     --     readnwrite_pio_external_connection.export
			receive_pio_external_connection_export        => CONNECTED_TO_receive_pio_external_connection_export,        --        receive_pio_external_connection.export
			reset_reset_n                                 => CONNECTED_TO_reset_reset_n,                                 --                                  reset.reset_n
			switch_pio_external_connection_export         => CONNECTED_TO_switch_pio_external_connection_export,         --         switch_pio_external_connection.export
			transmit_pio_external_connection_export       => CONNECTED_TO_transmit_pio_external_connection_export,       --       transmit_pio_external_connection.export
			transmitenable_pio_external_connection_export => CONNECTED_TO_transmitenable_pio_external_connection_export  -- transmitenable_pio_external_connection.export
		);

