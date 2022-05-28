----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.04.2022 09:56:19
-- Design Name: 
-- Module Name: ALU_TEST - Behavioral
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

entity ALU_TEST is
--  Port ( );
end ALU_TEST;

architecture Behavioral of ALU_TEST is

COMPONENT ALU
Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
       B : in STD_LOGIC_VECTOR (7 downto 0);
       Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0);
       S : out STD_LOGIC_VECTOR (7 downto 0);
       Flags : out STD_LOGIC_VECTOR (3 downto 0) := (others => '0'));
end COMPONENT;

   signal A_local : STD_LOGIC_VECTOR (7 downto 0);
   signal B_local : STD_LOGIC_VECTOR (7 downto 0);
   signal Ctrl_Alu_local : STD_LOGIC_VECTOR (2 downto 0);
   signal S_local : STD_LOGIC_VECTOR (7 downto 0);
   signal Flags_local : STD_LOGIC_VECTOR (3 downto 0) := (others => '0');
   
begin

Label_uut:ALU PORT MAP (
    A => A_local,
    B => B_local, 
    Ctrl_Alu => Ctrl_Alu_local,
    S => S_local,
    Flags => Flags_local
);

A_local <= x"01" after 5 ns, "11111111" after 10 ns, x"02" after 15 ns, x"ff" after 20 ns, x"01" after 23 ns, x"00" after 26 ns, x"05" after 36 ns ;
B_local <= x"01" after 5 ns, "11111111" after 10 ns, x"02" after 15 ns, x"02" after 20 ns, x"01" after 23 ns, x"FF" after 26 ns, x"06" after 36 ns   ;
Ctrl_Alu_local <= "001" after 1 ns, "010" after 11 ns, "011" after 21 ns ;  
end;
