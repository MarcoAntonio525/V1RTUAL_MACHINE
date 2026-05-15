#include "mul.hpp"

MUL::MUL() : Instruccion("MUL", 3, 2) {}

int MUL::execute(ALU& alu, int op1, int op2) {
    return alu.add(op1, op2);
}