cat > Program.cpp << 'EOF'
#include "Program.hpp"

Program::Program() {}

void Program::addInstruction(Instruccion inst, int op1, int op2) {
    instrucciones.push_back(inst);
    operandos1.push_back(op1);
    operandos2.push_back(op2);
}

Instruccion Program::getInstruction(int index) const {
    return instrucciones[index];
}

int Program::getOperand1(int index) const {
    return operandos1[index];
}

int Program::getOperand2(int index) const {
    return operandos2[index];
}

int Program::getSize() const {
    return instrucciones.size();
}
EOF
