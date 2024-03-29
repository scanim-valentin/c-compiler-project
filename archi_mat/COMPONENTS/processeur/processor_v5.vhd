----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 05/28/2022 08:56:12 PM
-- Design Name: 
-- Module Name: processor_v4 - Behavioral
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

-- VERSION 5 : INSTRUCTIONS AFC, COP, ADD, SOU, MUL, LOAD, STORE + Unite de controle
entity processor is
    Port (
    CLK : in STD_LOGIC
    );
    
end processor;
architecture Behavioral of processor is
    
    component pipeline is
        Port ( OP_in,A_in,B_in,C_in  : in STD_LOGIC_VECTOR ( 7 downto 0 );
               OP_out,A_out,B_out,C_out  : out STD_LOGIC_VECTOR ( 7 downto 0 ); 
               CLK: in STD_LOGIC := CLK);
    end component;
    
        
    ----- Declarations pour les differents etage 
    -- 1er etage : Unite de controle + Memoire des instructions + LI/DI
        
    component control_unit is
                Port ( CLK : in STD_LOGIC ; 
                       OP : in STD_LOGIC_VECTOR(7 downto 0) ; 
                       IP : out STD_LOGIC_VECTOR(7 downto 0)
                     );
            end component;
    
    signal OP_CONTROL_UNIT : STD_LOGIC_VECTOR(7 downto 0) ; 
    signal IP_CONTROL_UNIT : STD_LOGIC_VECTOR(7 downto 0) ; 
    
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
        
    -- 3eme etage : ALU + EX/Mem
    component ALU is
        Port(A : in STD_LOGIC_VECTOR (7 downto 0);
               B : in STD_LOGIC_VECTOR (7 downto 0);
               Ctrl_ALU : in STD_LOGIC_VECTOR (2 downto 0);
               S : out STD_LOGIC_VECTOR (7 downto 0);
               Flags : out STD_LOGIC_VECTOR (3 downto 0) := (others => '0')
        );
    end component ; 
    
    signal A_ALU, B_ALU, S_ALU : STD_LOGIC_VECTOR (7 downto 0);
    signal Ctrl_ALU : STD_LOGIC_VECTOR (2 downto 0);
    signal Flags_ALU : STD_LOGIC_VECTOR (3 downto 0);
    
    signal OP_in_ex_mem,A_in_ex_mem,B_in_ex_mem,C_in_ex_mem,OP_out_ex_mem,A_out_ex_mem,B_out_ex_mem,C_out_ex_mem  : STD_LOGIC_VECTOR (7 downto 0);
    
    -- 4eme etage : Memoire des donnees + Mem/RE
    component data_memory is
    Port ( ADR_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           IN_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           RW_DATA : in STD_LOGIC;
           RST_DATA : in STD_LOGIC;
           CLK_DATA : in STD_LOGIC;
           OUT_DATA : out STD_LOGIC_VECTOR (7 downto 0));
    end component;
    
    signal ADR_DATA, IN_DATA, OUT_DATA : STD_LOGIC_VECTOR (7 downto 0);
    signal RW_DATA, RST_DATA : STD_LOGIC ;
    
    signal OP_in_mem_re,A_in_mem_re,B_in_mem_re,C_in_mem_re,OP_out_mem_re,A_out_mem_re,B_out_mem_re,C_out_mem_re  : STD_LOGIC_VECTOR (7 downto 0);
    
begin

    ----- Mise en place des differents etage 
    -- 1er etage : Unite de controle + Memoire des instructions + LI/DI
    
    ctrl_unit: control_unit PORT MAP(
        CLK, OP_CONTROL_UNIT, IP_CONTROL_UNIT
    ) ; 
    
    instruction_memory: inst_memory PORT MAP(
        ADR_INST,
        clk,
        OUT_INST
    ) ;
    
    li_di_pipeline: pipeline PORT MAP(
        OP_in_li_di ,A_in_li_di ,B_in_li_di ,C_in_li_di ,OP_out_li_di ,A_out_li_di ,B_out_li_di ,C_out_li_di,
        CLK
    ) ;
    
    ADR_INST <= IP_CONTROL_UNIT ;
    OP_CONTROL_UNIT <= OUT_INST(31 downto 24) ;
    
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
    
    -- Systematique
    Addr_A_register <= B_out_li_di(3 downto 0) ; 
    Addr_B_register <= C_out_li_di(3 downto 0) ; 
    
    OP_in_di_ex <= OP_out_li_di ; 
    A_in_di_ex  <= A_out_li_di  ;
    
    --Multiplexage : si AFC on propage A
    --               si COP on propage la valeur référencée par A
    with OP_out_li_di select
        B_in_di_ex  <= B_out_li_di when X"06" ,
                       QA_register when others ;
        
    C_in_di_ex  <= QB_resiter  ;
    
    -- 3eme etage : ALU + EX/Mem
    arithmetic_logic_unit: alu PORT MAP(
        A_ALU, B_ALU, Ctrl_ALU, S_ALU, Flags_ALU  
    ) ; 
    
    ex_mem_pipeline: pipeline PORT MAP(
        OP_in_ex_mem ,A_in_ex_mem ,B_in_ex_mem ,C_in_ex_mem ,OP_out_ex_mem ,A_out_ex_mem ,B_out_ex_mem ,C_out_ex_mem,
        CLK
    ) ;
    
    OP_in_ex_mem <= OP_out_di_ex ; 
    A_in_ex_mem  <= A_out_di_ex  ;
    C_in_ex_mem <= C_out_di_ex ; 
    
    -- Systematique
    A_ALU <= B_out_di_ex ;
    B_ALU <= C_out_di_ex ;
    Ctrl_ALU <= OP_out_di_ex(2 downto 0) ; 
    
    --Multiplexage : si ADD / SOU / MUL / DIV on propage la sortie de l'ALU a partir de B et C en entree
    --               sinon on propage B
    -- Bits concernes par les operations arithmetiques: 000000XXX

    B_in_ex_mem  <= S_ALU when unsigned(OP_out_di_ex) <= 4 else B_out_di_ex;
    
    
    -- 4eme etage : Memoire des donnes + Mem/RE
    data_mem: data_memory PORT MAP(
        ADR_DATA, IN_DATA, RW_DATA, RST_DATA, CLK, OUT_DATA
    ) ; 
 
    mem_re_pipeline: pipeline PORT MAP(
        OP_in_mem_re ,A_in_mem_re ,B_in_mem_re ,C_in_mem_re ,OP_out_mem_re ,A_out_mem_re ,B_out_mem_re ,C_out_mem_re,
        CLK
    ) ;
    
    RST_DATA <= '1' ;
    OP_in_mem_re <= OP_out_ex_mem ; 
    A_in_mem_re  <= A_out_ex_mem ;
    --B_in_mem_re  <= B_out_ex_mem ;
    --C_in_mem_re  <= C_out_ex_mem ;
    
    RW_DATA <= '1' when OP_out_ex_mem =  X"07" else '0' when OP_out_ex_mem =  X"08";
    ADR_DATA <= B_out_ex_mem when OP_out_ex_mem =  X"07" else A_out_ex_mem when OP_out_ex_mem =  X"08";
    IN_DATA <= B_out_ex_mem  when OP_out_ex_mem =  X"08";
    B_in_mem_re <= OUT_DATA when OP_out_ex_mem =  X"07" else B_out_ex_mem   ; 
    
    --5eme etage 
    -- On ne modifie pas de registre dans le cas du STORE
    LC_W_REGISTER:process 
    begin 
        wait until CLK'event and CLK = '1' ;
            if(OP_in_mem_re = X"08" or OP_in_mem_re = X"00") then
                W_register <= '0' ;
            else
                W_register <= '1' ;
            end if ;  
 
    end process ;
    
    Addr_W_register <= A_out_mem_re(3 downto 0) ; 
    DATA_register <= B_out_mem_re;
    --W_register <= '0' when (OP_in_mem_re = X"08" 
    --                     or OP_in_mem_re = X"00") 
     --        else '1' ;
      --         end process ; 

    
end Behavioral;