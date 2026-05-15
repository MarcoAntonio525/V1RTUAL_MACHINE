// ADD.hpp
#ifndef ADD_HPP
#define ADD_HPP
#include "Instruccion.hpp"
#include "ALU.hpp"

// ADD.hpp - Suma
class ADD : public Instruccion {
public:
    ADD() : Instruccion("ADD", 1, 2) {}
    int execute(ALU& alu, int op1, int op2) { return alu.add(op1, op2); }
};

#endif
