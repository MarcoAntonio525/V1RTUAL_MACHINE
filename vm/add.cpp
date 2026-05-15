// ADD.cpp
#include "ADD.hpp"

ADD::ADD() : Instruccion("ADD", 1, 2) {}  // siempre igual

int ADD::execute(ALU& alu, int op1, int op2) {
    return alu.add(op1, op2);
}