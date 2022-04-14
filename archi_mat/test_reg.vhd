----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.04.2022 11:41:03
-- Design Name: 
-- Module Name: test_reg - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL ; 
use IEEE.NUMERIC_STD.ALL ; 

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity test_reg is
end test_reg;

architecture Behavioral of test_reg is

component BANC_REGISTRES is
    Port ( Addr_A : in STD_LOGIC_VECTOR (3 downto 0);
           Addr_B : in STD_LOGIC_VECTOR (3 downto 0);
           Addr_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0) ) ;
end component ;

signal adr_A, adr_B, adr_W : STD_LOGIC_VECTOR (3 downto 0);
signal W, RST, CLk : std_logic;
signal data, QA, QB : std_logic_vector (7 downto 0);

begin

uut: banc_registres port map (adr_A,adr_B, adr_W, W, data, rst, clk, QA, QB) ;
clk <= not clk after 5 ns;

rst <= '0' , '1' after 30 ns;

adr_A <= X"5" after 30 ns;
adr_B <= X"F" after 30 ns;
W <= '1' after 30 ns, '0' after 50 ns ;
adr_W <= X"5" after 30 ns ;
DATA <= X"66" after 30 ns ;  
adr_W <= X"F" after 40 ns ;
DATA <= X"77" after 40 ns ; 




end Behavioral;
