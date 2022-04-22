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
    Port ( CLK : in STD_LOGIC);
end pipeline;



architecture Behavioral of pipeline is

component alu is
    Port ( A : in STD_LOGIC_VECTOR (7 downto 0);
           B : in STD_LOGIC_VECTOR (7 downto 0);
           Ctrl_Alu : in STD_LOGIC_VECTOR (2 downto 0);
           S : out STD_LOGIC_VECTOR (7 downto 0);
           Flags : out STD_LOGIC_VECTOR (3 downto 0) := (others => '0'));
end component ;

component banc_registre is
    Port ( Addr_A : in STD_LOGIC_VECTOR (3 downto 0);
           Addr_B : in STD_LOGIC_VECTOR (3 downto 0);
           Addr_W : in STD_LOGIC_VECTOR (3 downto 0);
           W : in STD_LOGIC; --Actif a l'etat haut
           DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RST : in STD_LOGIC; --Actif a l'etat bas
           CLK : in STD_LOGIC;
           QA : out STD_LOGIC_VECTOR (7 downto 0);
           QB : out STD_LOGIC_VECTOR (7 downto 0) ) ;
end component ;

component data_memory is
    Port ( ADR_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           IN_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RW_DATA : in STD_LOGIC;
           RST_DATA : in STD_LOGIC;
           CLK_DATA : in STD_LOGIC;
           OUT_DATA : out STD_LOGIC_VECTOR (7 downto 0));
end component ;

component inst_memory is
    Port ( ADR_INST : in STD_LOGIC_VECTOR (7 downto 0);
           CLK_INST : in STD_LOGIC;
           OUT_INST : out STD_LOGIC_VECTOR (31 downto 0));
end component ;


begin
    --let's go

end Behavioral;
