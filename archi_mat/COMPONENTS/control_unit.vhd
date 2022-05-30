----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 30.05.2022 11:38:36
-- Design Name: 
-- Module Name: control_unit - Behavioral
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
use IEEE.STD_LOGIC_ARITH.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity control_unit is
    Port ( CLK : in STD_LOGIC ; 
           OP : in STD_LOGIC_VECTOR(7 downto 0) ; 
           IP : out STD_LOGIC_VECTOR(7 downto 0) := X"00"
         );
end control_unit;


architecture Behavioral of control_unit is
signal PC : unsigned(7 downto 0) := X"00"; 
signal cycle : unsigned(7 downto 0) := X"00"; 

begin
    process 
    begin
        wait until CLK'event and CLK = '1' ;
                
               if cycle > 1 then 
                    PC <= PC + 1 ; 
                    IP <= STD_LOGIC_VECTOR(PC) ;
                    cycle <= x"00" ;
                else
                    cycle <= cycle + 1 ;
                END If ; 
    end process ; 

end Behavioral;
