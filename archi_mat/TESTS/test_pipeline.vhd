----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.05.2022 19:25:52
-- Design Name: 
-- Module Name: test_pipeline - Behavioral
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

entity test_pipeline is
end test_pipeline;

architecture Behavioral of test_pipeline is
    COMPONENT Pipeline IS
    Port (
               OP_in,A_in,B_in,C_in : in STD_LOGIC_VECTOR (7 downto 0);
               OP_out, A_out, B_out, C_out : out STD_LOGIC_VECTOR (7 downto 0);
               Clk : in STD_LOGIC 
          );
     end COMPONENT ;
    signal OP_in,A_in,B_in,C_in,OP_out, A_out, B_out, C_out  : STD_LOGIC_VECTOR (7 downto 0);
    signal clk: STD_LOGIC := '1';
    constant Clock_period : Time := 10 ns ;
begin
    Label_uut : pipeline port map (OP_in,A_in,B_in,C_in,OP_out, A_out, B_out, C_out, clk) ;
    Clock_process: process
        begin
            clk <= not(clk);
            wait for Clock_period/2;
        end process;
        
     OP_in <= X"06" ; --CODE OP AFC
     A_in <= X"00" ;
     B_in <= X"48" ;
     C_in <= X"00" ;
          
end Behavioral;
