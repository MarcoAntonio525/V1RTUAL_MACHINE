#ifndef CU_HPP
#define CU_HPP

#include <string>
#include "Instruccion.hpp"
#include "Program.hpp"
#include "ALU.hpp"
#include "Registros.hpp"   

class CU
{
private:
    std::string status;
    ALU alu;
    Registros reg;          // banco de registros
    
public:
    CU();
    CU(std::string theStatus);
    
    Instruccion fetch(Program& theProgram);
    int decode(const Instruccion& theInstruction);
    void execute(int theCode, int operand1, int operand2);
    void run(Program& theProgram);
    void displayRegistros() const;  
};

#endif