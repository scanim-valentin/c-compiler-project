----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22.04.2022 12:04:48
-- Design Name: 
-- Module Name: pipeline - Behavioral
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

entity pipeline is
    Port ( OP_in,A_in,B_in,C_in  : in STD_LOGIC_VECTOR ( 7 downto 0 );
           OP_out,A_out,B_out,C_out  : out STD_LOGIC_VECTOR ( 7 downto 0 ); 
           CLK: in STD_LOGIC);
end pipeline;



architecture Behavioral of pipeline is    
begin
    process
    begin
        wait until CLK'event and CLK = '1' ;
        OP_out <= OP_in ; 
        A_out <= A_in ; 
        B_out <= B_in ; 
        C_out <= C_in ;                         
    end process ;
end Behavioral;
