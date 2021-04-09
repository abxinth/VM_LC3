enum
{
    MR_KBSR = 0xFE00, /* keyboard status */
    MR_KBDR = 0xFE02  /* keyboard data */
};
uint16_t memory[65536];//2^16 locations
/*
Registers
r0-r7 general purpose
PC->program counter
COND->Condition flag
*/
enum Registers{
    R0,R1,R2,R3,R4,R5,R6,R7,PC,COND
};
uint16_t reg[10];///array to store the registers

enum Opcodes{
    BR,ADD,LD,ST,JSR,AND,LDR,STR,RTI,NOT,LDI,STI,JMP,RES,LEA,TRAP
};

enum cond_flags{
    POS = 1<<0,
    ZERO = 1<<1,
    NEG = 1<<2,
};
