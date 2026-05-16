#include "sub.hpp"

SUB::SUB() : Instruccion("SUB", 81, 2) {}

int SUB::execute(ALU& alu, int op1, int op2) {
    return alu.sub(op1, op2);
}
