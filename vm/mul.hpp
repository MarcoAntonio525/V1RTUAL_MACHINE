// ADD.hpp
#ifndef ADD_HPP
#define ADD_HPP
#include "Instruccion.hpp"
#include "ALU.hpp"

class MUL : public Instruccion {
public:
    MUL() : Instruccion("MUL", 3, 2) {}
    int execute(ALU& alu, int op1, int op2) { return alu.mul(op1, op2); }
};
#endif
