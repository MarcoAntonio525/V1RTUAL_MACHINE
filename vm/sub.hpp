#ifndef SUB_HPP
#define SUB_HPP

#include "Instruccion.hpp"
#include "ALU.hpp"

class SUB : public Instruccion {
public:
    SUB();
    int execute(ALU& alu, int op1, int op2) override;
};

#endif
