#include "Program.hpp"

Program::Program() : size(0) {
    // Inicializar operandos en 0
    for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
        operand1[i] = 0;
        operand2[i] = 0;
    }
}

bool Program::addInstruction(Instruccion theInstruction, int op1, int op2) {
    if (size >= MAX_INSTRUCTIONS) {
        return false;  // programa lleno
    }
    instructions[size] = theInstruction;
    operand1[size] = op1;
    operand2[size] = op2;
    size++;
    return true;
}

Instruccion Program::getInstruction(int position) const{
    return instructions[position];
}

int Program::getOperand1(int position) const{
    return operand1[position];
}

int Program::getOperand2(int position) const{
    return operand2[position];
}

int Program::getSize() const{
    return size;
}