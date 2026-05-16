#include "ADD.hpp"

ADD::ADD() : Instruccion("ADD", 80, 2) {}

int ADD::execute(ALU& alu, int op1, int op2) {
    return alu.add(op1, op2);
}
