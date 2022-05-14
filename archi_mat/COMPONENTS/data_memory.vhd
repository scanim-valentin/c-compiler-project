----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.04.2022 11:03:52
-- Design Name: 
-- Module Name: data_memory - Behavioral
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

entity data_memory is
    Port ( ADR_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           IN_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RW_DATA : in STD_LOGIC;
           RST_DATA : in STD_LOGIC;
           CLK_DATA : in STD_LOGIC;
           OUT_DATA : out STD_LOGIC_VECTOR (7 downto 0));
end data_memory;

architecture Behavioral of data_memory is

type mem is array (0 to 254) of STD_LOGIC_VECTOR (7 downto 0);
signal memory: mem;

begin

     process
    begin
        wait until CLK_DATA'event and CLK_DATA = '1' ;
        
        if RST_DATA = '0' then
        
           memory <= (others => X"00") ;
           
        elsif RW_DATA = '0' then
            --Acces en ecriture
            memory(to_integer(unsigned(ADR_DATA))) <= IN_DATA ;
        elsif RW_DATA = '1' then
            --Acces en lecture
            OUT_DATA <= memory(to_integer(unsigned(ADR_DATA))) ;
                    
        end if;

    end process;

end Behavioral;
