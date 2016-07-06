	component sRamQsys is
		port (
			address_pio_external_connection_export    : out std_logic_vector(10 downto 0);                    -- export
			chipselect_pio_external_connection_export : out std_logic;                                        -- export
			clk_clk                                   : in  std_logic                     := 'X';             -- clk
			dataout_export                            : out std_logic_vector(7 downto 0);                     -- export
			enable_pio_external_connection_export     : out std_logic;                                        -- export
			led_pio_external_connection_export        : out std_logic_vector(7 downto 0);                     -- export
			readnwrite_pio_external_connection_export : out std_logic;                                        -- export
			reset_reset_n                             : in  std_logic                     := 'X';             -- reset_n
			datain_export                             : in  std_logic_vector(7 downto 0)  := (others => 'X')  -- export
		);
	end component sRamQsys;

	u0 : component sRamQsys
		port map (
			address_pio_external_connection_export    => CONNECTED_TO_address_pio_external_connection_export,    --    address_pio_external_connection.export
			chipselect_pio_external_connection_export => CONNECTED_TO_chipselect_pio_external_connection_export, -- chipselect_pio_external_connection.export
			clk_clk                                   => CONNECTED_TO_clk_clk,                                   --                                clk.clk
			dataout_export                            => CONNECTED_TO_dataout_export,                            --                            dataout.export
			enable_pio_external_connection_export     => CONNECTED_TO_enable_pio_external_connection_export,     --     enable_pio_external_connection.export
			led_pio_external_connection_export        => CONNECTED_TO_led_pio_external_connection_export,        --        led_pio_external_connection.export
			readnwrite_pio_external_connection_export => CONNECTED_TO_readnwrite_pio_external_connection_export, -- readnwrite_pio_external_connection.export
			reset_reset_n                             => CONNECTED_TO_reset_reset_n,                             --                              reset.reset_n
			datain_export                             => CONNECTED_TO_datain_export                              --                             datain.export
		);

