#ifndef DIV_HPP
#define DIV_HPP

#include "Instruccion.hpp"
#include "ALU.hpp"

class DIV : public Instruccion {
public:
    DIV();
    int execute(ALU& alu, int op1, int op2) override;
};

#endif
