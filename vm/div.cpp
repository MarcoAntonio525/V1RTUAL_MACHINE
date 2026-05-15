// ADD.cpp
#include "div.hpp"

DIV::DIV() : Instruccion("DIV", 4, 2) {}

int DIV::execute(ALU& alu, int op1, int op2) {
    return alu.add(op1, op2);
}