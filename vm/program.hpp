cat > Program.hpp << 'EOF'
#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <vector>
#include "Instruccion.hpp"

class Program {
private:
    std::vector<Instruccion> instrucciones;
    std::vector<int> operandos1;
    std::vector<int> operandos2;

public:
    Program();
    void addInstruction(Instruccion inst, int op1, int op2);
    Instruccion getInstruction(int index) const;
    int getOperand1(int index) const;
    int getOperand2(int index) const;
    int getSize() const;  // ← Mayúscula S
};

#endif
EOF
