----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.04.2022 11:17:02
-- Design Name: 
-- Module Name: test_mem - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity test_mem is
    
end test_mem;

architecture Behavioral of test_mem is

    component data_memory is
    Port ( ADR_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           IN_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RW_DATA : in STD_LOGIC;
           RST_DATA : in STD_LOGIC;
           CLK_DATA : in STD_LOGIC;
           OUT_DATA : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    component inst_memory is
        Port ( ADR_INST : in STD_LOGIC_VECTOR (7 downto 0);
               CLK_INST : in STD_LOGIC;
               OUT_INST : out STD_LOGIC_VECTOR (31 downto 0));
    end component;
    
    signal adr_data : STD_LOGIC_VECTOR (7 downto 0);
    signal in_data, out_data, adr_inst : STD_LOGIC_VECTOR (7 downto 0);
    signal rw_data,rst_data: std_logic;
    
    signal CLK: std_logic := '1';
    signal out_inst : std_logic_vector (31 downto 0);
        
    constant Clock_period: time := 10 ns;
    
    
begin

    DATA_MEM: data_memory port map (adr_data,in_data, rw_data, rst_data, CLK, out_data) ;
    
    INST_MEM: inst_memory port map (adr_inst, CLK, out_inst) ;
        
    Clock_process: process
    begin
                clk <= not(clk);
                wait for Clock_period/2;
    end process ;
    
    rst_data <= '0',  '1' after 15 ns;
        
    adr_data <= X"05" ;
    in_data <= X"0F" ;
    rw_data <= '1', '0' after 30 ns, '1' after 50 ns ;
    
    adr_inst <= X"65" ;
    
end Behavioral;
