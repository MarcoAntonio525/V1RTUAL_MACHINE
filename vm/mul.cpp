#include "mul.hpp"

MUL::MUL() : Instruccion("MUL", 82, 2) {}

int MUL::execute(ALU& alu, int op1, int op2) {
    return alu.mul(op1, op2);
}
