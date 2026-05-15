#ifndef ADD_HPP
#define ADD_HPP
#include "Instruccion.hpp"
#include "ALU.hpp"
class SUB : public Instruccion {
public:
    SUB() : Instruccion("SUB", 2, 2) {}
    int execute(ALU& alu, int op1, int op2) { return alu.sub(op1, op2); }
};
#endif