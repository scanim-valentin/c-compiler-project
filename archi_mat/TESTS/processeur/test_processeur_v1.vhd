----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 26.05.2022 09:53:03
-- Design Name: 
-- Module Name: test_processeur_v1 - Behavioral
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

entity test_processeur_v1 is
--  Port ( );
end test_processeur_v1;

architecture Behavioral of test_processeur_v1 is
    component processor is
        port(
        Clk : in STD_LOGIC 
              );
         end COMPONENT ;
    signal clk: STD_LOGIC := '1';
    constant Clock_period : Time := 10 ns ;
begin


end Behavioral;
