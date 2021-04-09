#include<iostream>

#include "Hardware.h"
#include "mem_write.h"
bool running = true;
#include "SupportFunctions.h"
#include "TrapRoutines.h"
#include "LoadPrograms.h"
using namespace std;


int main(){

enum{PC_START = 0x3000};
reg[PC] = PC_START;

while(running){
    uint16_t instruction = 1;//mem_read(reg[PC]++);
    uint16_t op = instruction >> 12;
    switch(op){
    case ADD:
        add(instruction);
        break;
    case AND:
        bw_and(instruction);
        break;
    case NOT:
        bw_not(instruction);
        break;
    case BR:
        br(instruction);
        break;
    case JMP:
        jmp(instruction);
        break;
    case JSR:
        jsr(instruction);
        break;
    case LD:
        ld(instruction);
        break;
    case LDI:
         ldi(instruction);
        break;
    case LDR:
        ldr(instruction);
        break;
    case LEA:
        lea(instruction);
        break;
    case ST:
        st(instruction);
    case STI:
        sti(instruction);
        break;
    case STR:
        sti(instruction);
        break;
    case TRAP:
        trap(instruction);
        break;
    default:
        break;

    }

}

cout<<"ADASD";
return 0;
}
