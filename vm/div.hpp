// ADD.hpp
#ifndef ADD_HPP
#define ADD_HPP
#include "Instruccion.hpp"
#include "ALU.hpp"

// ADD.hpp - Suma
class DIV : public Instruccion {
public:
    DIV() : Instruccion("DIV", 4, 2) {}
    int execute(ALU& alu, int op1, int op2) { return alu.div(op1, op2); }
};
#endif
