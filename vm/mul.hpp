#ifndef MUL_HPP
#define MUL_HPP

#include "Instruccion.hpp"
#include "ALU.hpp"

class MUL : public Instruccion {
public:
    MUL();
    int execute(ALU& alu, int op1, int op2) override;
};

#endif
