----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 08.04.2022 10:18:39
-- Design Name: 
-- Module Name: ALU - Behavioral
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
-- Ctrl_Alu : '000' : Add ; '001' : Sou ; '010' : Mul ; '100' : Div
-- Flags : <N,O,Z,C>
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL; 
use IEEE.STD_LOGIC_UNSIGNED.ALL ; 


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
    Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           Flags : out STD_LOGIC_VECTOR (3 downto 0) := (others => '0'));
end ALU;

architecture Behavioral of ALU is

    signal S_Extended : STD_LOGIC_VECTOR (15 downto 0) ;
    signal A_Extended : STD_LOGIC_VECTOR (15 downto 0) ;
    signal B_Extended : STD_LOGIC_VECTOR (15 downto 0) ;
    
begin
        
        A_Extended <= x"00" & A ; 
        B_Extended <= x"00" & B ;
        
        --add
        S_Extended <= (A_Extended + B_Extended) when Ctrl_Alu = "000" else
        --sou
                      (A_Extended - B_Extended) when (Ctrl_Alu = "001") else
        --mul
                      (A * B) when (Ctrl_Alu = "010") ;
            
        --Gestion des flags           
        --C (Add)
        Flags(0) <= '1' when ( (Ctrl_Alu = "000" OR Ctrl_Alu = "001") AND S_Extended(8) = '1') else '0';
        
        --Z
        Flags(1) <= '1' when S_Extended = X"00" else '0';
        
        --O (Mul)
        Flags(2) <= '1' when ( (Ctrl_Alu = "010") AND S_Extended(8) = '1') else '0';
                        
        --N 
        Flags(3) <= '1' when S_Extended < X"00" else '0';
                
                
        S <= S_Extended (7 downto 0) ; 

end Behavioral;
