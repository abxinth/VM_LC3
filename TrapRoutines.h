enum
{
    TRAP_GETC = 0x20,  /* get character from keyboard, not echoed onto the terminal */
    TRAP_OUT = 0x21,   /* output a character */
    TRAP_PUTS = 0x22,  /* output a word string */
    TRAP_IN = 0x23,    /* get character from keyboard, echoed onto the terminal */
    TRAP_PUTSP = 0x24, /* output a byte string */
    TRAP_HALT = 0x25   /* halt the program */
};
void trap_puts(){
    uint16_t* c = memory + reg[R0];
    while (*c)
    {
        putc((char)*c, stdout);
        ++c;
    }
    fflush(stdout);
}
void trap_getc(){
    reg[R0] = (uint16_t)getchar();
}
void trap_out(){
putc((char)reg[RO], stdout);
fflush(stdout);

}
void trap_in{
    printf("Enter a character: ");
    char c = getchar();
    putc(c, stdout);
    reg[R0] = (uint16_t)c;
}
void trap_putsp(){
    uint16_t* c = memory + reg[R_R0];
    while (*c)
    {
        char char1 = (*c) & 0xFF;
        putc(char1, stdout);
        char char2 = (*c) >> 8;
        if (char2) putc(char2, stdout);
        ++c;
    }
    fflush(stdout);

}

void trap_halt(){
puts("HALT");
fflush(stdout);
running = 0;
}

void trap(uint16_t instr){
    switch (instr & 0xFF)
{
    case TRAP_GETC:
        trap_getc();
        break;
    case TRAP_OUT:
       trap_out();
        break;
    case TRAP_PUTS:
       trap_puts();
        break;
    case TRAP_IN:
       trap_in();
        break;
    case TRAP_PUTSP:
        trap_putsp();
        break;
    case TRAP_HALT:
       trap_halt();
        break;
}

}
