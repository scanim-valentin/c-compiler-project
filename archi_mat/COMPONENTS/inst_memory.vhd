----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.04.2022 11:03:52
-- Design Name: 
-- Module Name: inst_memory - Behavioral
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

entity inst_memory is
    Port ( ADR_INST : in STD_LOGIC_VECTOR (7 downto 0);
           CLK_INST : in STD_LOGIC;
           OUT_INST : out STD_LOGIC_VECTOR (31 downto 0));
end inst_memory;

architecture Behavioral of inst_memory is

type mem is array (0 to 255) of STD_LOGIC_VECTOR (31 downto 0);
signal memory: mem := (others => X"05030500");

begin

     process
    begin
        wait until CLK_INST'event and CLK_INST = '1' ;
            --Acces en lecture
            OUT_INST <= memory(to_integer(unsigned(ADR_INST))) ;
    end process;

end Behavioral;
