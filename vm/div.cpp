#include "div.hpp"

DIV::DIV() : Instruccion("DIV", 83, 2) {}

int DIV::execute(ALU& alu, int op1, int op2) {
    return alu.div(op1, op2);
}
