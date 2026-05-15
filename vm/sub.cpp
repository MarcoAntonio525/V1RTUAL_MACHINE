#include "sub.hpp"

SUB::SUB() : Instruccion("SUB", 2, 2) {}

int SUB::execute(ALU& alu, int op1, int op2) {
    return alu.add(op1, op2);
}