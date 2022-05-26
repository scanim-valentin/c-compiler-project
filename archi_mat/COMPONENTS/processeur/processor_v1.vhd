----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/21/2022 02:38:19 AM
-- Design Name: 
-- Module Name: processor - Behavioral
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


-- VERSION 1 : INSTRUCTION AFC
entity processor is
    Port (
    CLK : in STD_LOGIC;
    PC : in STD_LOGIC_VECTOR (7 downto 0) := (others => '0')
--    Debug : in STD_LOGIC;
--    Res : out STD_LOGIC_VECTOR (7 downto 0)
    );
    
end processor;

architecture Behavioral of processor is
    
    component pipeline is
        Port ( OP_in,A_in,B_in,C_in  : in STD_LOGIC_VECTOR ( 7 downto 0 );
               OP_out,A_out,B_out,C_out  : out STD_LOGIC_VECTOR ( 7 downto 0 ); 
               CLK: in STD_LOGIC := CLK);
    end component;
    
    ----- Declarations pour les differents etage 
    -- 1er etage : Memoire des instructions + LI/DI
    component inst_memory is
        Port ( ADR_INST : in STD_LOGIC_VECTOR (7 downto 0);
               CLK_INST : in STD_LOGIC;
               OUT_INST : out STD_LOGIC_VECTOR (31 downto 0));
    end component;
    
 
    signal ADR_INST  : STD_LOGIC_VECTOR (7 downto 0);
    signal OUT_INST : STD_LOGIC_VECTOR (31 downto 0);
    
    signal OP_in_li_di ,A_in_li_di ,B_in_li_di ,C_in_li_di ,OP_out_li_di ,A_out_li_di ,B_out_li_di ,C_out_li_di   : STD_LOGIC_VECTOR (7 downto 0);
    
    -- 2eme etage : Banc de registres + DI/EX
    component BANC_REGISTRES is
        Port ( Addr_A : in STD_LOGIC_VECTOR (3 downto 0);
               Addr_B : in STD_LOGIC_VECTOR (3 downto 0);
               Addr_W : in STD_LOGIC_VECTOR (3 downto 0);
               W : in STD_LOGIC; --Actif a l'etat haut
               DATA : in STD_LOGIC_VECTOR (7 downto 0);
               RST : in STD_LOGIC; --Actif a l'etat bas
               CLK : in STD_LOGIC;
               QA : out STD_LOGIC_VECTOR (7 downto 0);
               QB : out STD_LOGIC_VECTOR (7 downto 0) ) ;
    end component;
    
    
    signal W_register, RST_register : STD_LOGIC ;
    signal Addr_A_register, Addr_B_register, Addr_W_register  : STD_LOGIC_VECTOR (3 downto 0);
    signal DATA_register, QA_register, QB_resiter  : STD_LOGIC_VECTOR (7 downto 0);
    
    signal OP_in_di_ex ,A_in_di_ex ,B_in_di_ex ,C_in_di_ex ,OP_out_di_ex ,A_out_di_ex ,B_out_di_ex ,C_out_di_ex   : STD_LOGIC_VECTOR (7 downto 0);
    signal OP_in_ex_mem,A_in_ex_mem,B_in_ex_mem,C_in_ex_mem,OP_out_ex_mem,A_out_ex_mem,B_out_ex_mem,C_out_ex_mem  : STD_LOGIC_VECTOR (7 downto 0);
    signal OP_in_mem_re,A_in_mem_re,B_in_mem_re,C_in_mem_re,OP_out_mem_re,A_out_mem_re,B_out_mem_re,C_out_mem_re  : STD_LOGIC_VECTOR (7 downto 0);
    
begin

    ----- Mise en place des differents etage 
    -- 1er etage : Memoire des instructions + LI/DI
    instruction_memory: inst_memory PORT MAP(
        ADR_INST,
        clk,
        OUT_INST
    ) ;
    
    li_di_pipeline: pipeline PORT MAP(
        OP_in_li_di ,A_in_li_di ,B_in_li_di ,C_in_li_di ,OP_out_li_di ,A_out_li_di ,B_out_li_di ,C_out_li_di,
        CLK
    ) ;
    
    ADR_INST <= PC ;
    
    OP_in_li_di <= OUT_INST(31 downto 24) ;
    A_in_li_di  <= OUT_INST(23 downto 16) ;
    B_in_li_di  <= OUT_INST(15 downto 8 ) ;
    C_in_li_di  <= OUT_INST(7  downto 0 ) ;
    
    -- 2eme etage : Banc de registres + DI/EX
    register_file: banc_registres PORT MAP(
        Addr_A_register, Addr_B_register, Addr_W_register, W_register,DATA_register, RST_register, clk, QA_register, QB_resiter
    ) ;
    
    di_ex_pipeline: pipeline PORT MAP(
        OP_in_di_ex ,A_in_di_ex ,B_in_di_ex ,C_in_di_ex ,OP_out_di_ex ,A_out_di_ex ,B_out_di_ex ,C_out_di_ex,
        CLK
    ) ;
    
    OP_in_di_ex <= OP_out_li_di ; 
    A_in_di_ex  <= A_out_li_di  ;
    B_in_di_ex  <= B_out_li_di when OP_out_li_di = X"06" else QA_register
--                   when OP_out_li_di = X"05"
                   ;
    C_in_di_ex  <= C_out_li_di  ;
    
    -- 3eme etage : ALU + EX/Mem
    ex_mem_pipeline: pipeline PORT MAP(
        OP_in_ex_mem ,A_in_ex_mem ,B_in_ex_mem ,C_in_ex_mem ,OP_out_ex_mem ,A_out_ex_mem ,B_out_ex_mem ,C_out_ex_mem,
        CLK
    ) ;
    
    OP_in_ex_mem <= OP_out_di_ex ; 
    A_in_ex_mem  <= A_out_di_ex  ;
    B_in_ex_mem  <= B_out_di_ex  ;
    C_in_ex_mem  <= C_out_di_ex  ;
    
    -- 4eme etage : Memoire des donnes + Mem/RE
    mem_re_pipeline: pipeline PORT MAP(
        OP_in_mem_re ,A_in_mem_re ,B_in_mem_re ,C_in_mem_re ,OP_out_mem_re ,A_out_mem_re ,B_out_mem_re ,C_out_mem_re,
        CLK
    ) ;
    
    OP_in_mem_re <= OP_out_ex_mem ; 
    A_in_mem_re  <= A_out_ex_mem  ;
    B_in_mem_re  <= B_out_ex_mem  ;
    C_in_mem_re  <= C_out_ex_mem  ;
    
    --5eme etage 
    W_register <= '1' when OP_in_mem_re = X"06";
    Addr_W_register <= A_out_mem_re(3 downto 0) ; 
    DATA_register <= B_out_mem_re;
    
end Behavioral;
