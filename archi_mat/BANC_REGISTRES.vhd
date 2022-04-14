----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.04.2022 10:47:57
-- Design Name: 
-- Module Name: BANC_REGISTRES - Behavioral
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

entity BANC_REGISTRES is
    Port ( Addr_A : in STD_LOGIC_VECTOR (3 downto 0);
           Addr_B : in STD_LOGIC_VECTOR (3 downto 0);
           Addr_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC;
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC;
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0) ) ;
end BANC_REGISTRES;

architecture Behavioral of BANC_REGISTRES is

type banc is array (0 to 15) of STD_LOGIC_VECTOR (7 downto 0);
signal registers: banc;


begin
    process
    begin
        wait until CLK'event and CLK = '1' ;
        
        if RST = '0' then
        
           registers <= (others => X"00") ;
           
        elsif W = '1' then
            --Acces en ecriture
            registers(to_integer(unsigned(Addr_W))) <= DATA ;
        
            
        end if;
        
    end process;
    
    QA <= registers(to_integer(unsigned(Addr_A))) ; 
    QB <= registers(to_integer(unsigned(Addr_B))) ; 
    
end Behavioral;
