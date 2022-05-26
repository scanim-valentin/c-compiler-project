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
use IEEE.STD_LOGIC_ARITH.ALL; 

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity test_processeur_v1 is
end test_processeur_v1;

architecture Behavioral of test_processeur_v1 is
    component processor is
        Port (
        CLK : in STD_LOGIC;
        PC : in STD_LOGIC_VECTOR (7 downto 0));
    end COMPONENT ;
    
    signal local_clk: STD_LOGIC := '1';
    signal local_pc: STD_LOGIC_VECTOR (7 downto 0);
    
    constant Clock_period : Time := 10 ns ;
    
    begin
    
    Label_uut: processor PORT MAP (
    CLK => local_clk,
    PC => local_pc
    );
    
    Clock_process: process
        begin
            local_clk <= not(local_clk);
            wait for Clock_period/2;
        end process;
        
    Instruct_select: process
    begin
        for instruction_number in 0 to 255 loop
            local_pc <= conv_std_logic_vector(instruction_number,local_pc'length);
            wait for 50 ns ; 
        end loop;
    end process ; 
end Behavioral;
