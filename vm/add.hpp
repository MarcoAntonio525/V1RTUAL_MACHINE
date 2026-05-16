#ifndef ADD_HPP
#define ADD_HPP

#include "Instruccion.hpp"
#include "ALU.hpp"

class ADD : public Instruccion {
public:
    ADD();
    int execute(ALU& alu, int op1, int op2) override;
};

#endif
