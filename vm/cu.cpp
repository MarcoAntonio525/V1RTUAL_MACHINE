#include "CU.hpp"
#include <iostream>
#include "lexical_analyzer.hpp"

CU::CU() : status("idle") {}

CU::CU(std::string theStatus) : status(theStatus) {}

Instruccion CU::fetch(Program& theProgram)
{
    reg.setMAR(reg.getPC());
    Instruccion inst = theProgram.getInstruction(reg.getMAR());
    reg.setMBR(inst.getCode());
    reg.setIR(reg.getMBR());
    reg.incrementPC();
    return inst;
}

int CU::decode(const Instruccion& theInstruction)
{
    LexicalAnalyzer lexer;
    std::string name = theInstruction.getName();
    int code = lexer.getInstructionCode(name);
    
    if (code == -1) {
        std::cout << "Error: Instrucción '" << name << "' no reconocida" << std::endl;
    }
    return code;
}

void CU::execute(int theCode, int operand1, int operand2)
{
    int result;
    
    switch (theCode)
    {
        case 50:  // START
            std::cout << "=== INICIO DEL PROGRAMA ===" << std::endl;
            status = "running";
            reg.reset();
            break;
            
        case 51:  // STOP
            std::cout << "=== FIN DEL PROGRAMA ===" << std::endl;
            status = "stopped";
            break;
            
        case 80:  // ADD
            result = alu.add(operand1, operand2);
            reg.setAC(result);
            std::cout << "ADD: " << operand1 << " + " << operand2 << " = " << result << std::endl;
            break;
            
        case 81:  // SUB
            result = alu.sub(operand1, operand2);
            reg.setAC(result);
            std::cout << "SUB: " << operand1 << " - " << operand2 << " = " << result << std::endl;
            break;
            
        case 82:  // MUL
            result = alu.mul(operand1, operand2);
            reg.setAC(result);
            std::cout << "MUL: " << operand1 << " * " << operand2 << " = " << result << std::endl;
            break;
            
        case 83:  // DIV
            if (operand2 != 0) {
                result = alu.div(operand1, operand2);
                reg.setAC(result);
                std::cout << "DIV: " << operand1 << " / " << operand2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division entre cero" << std::endl;
            }
            break;
            
        case 90:  // MOV
            reg.setAL(operand1);
            std::cout << "MOV: AL = " << operand1 << std::endl;
            break;
            
        case 91:  // STO
            reg.setMAR(operand2);
            reg.setMBR(operand1);
            std::cout << "STO: Memoria[" << reg.getMAR() << "] = " << reg.getMBR() << std::endl;
            break;
            
        default:
            std::cout << "Error: Instruccion desconocida (codigo: " << theCode << ")" << std::endl;
            break;
    }
}

void CU::run(Program& theProgram)
{
    status = "running";
    reg.reset();
    reg.setPC(0);
    
    std::cout << "\n=== MAQUINA VIRTUAL INICIADA ===" << std::endl;
    
    while (status == "running" && reg.getPC() < theProgram.getSize())
    {
        int ciclo = reg.getPC() + 1;
        std::cout << "\n========== CICLO " << ciclo << " ==========" << std::endl;
        
        // ===== FETCH =====
        std::cout << "\n--- FETCH ---" << std::endl;
        Instruccion inst = fetch(theProgram);
        std::cout << "PC: " << (reg.getPC() - 1) << std::endl;
        std::cout << "IR: " << reg.getIR() << " (Instruccion: " << inst.getName() << ")" << std::endl;
        std::cout << "MAR: " << reg.getMAR() << std::endl;
        std::cout << "MBR: " << reg.getMBR() << std::endl;
        
        // ===== DECODE =====
        std::cout << "\n--- DECODE ---" << std::endl;
        int code = decode(inst);
        std::cout << "Codigo de operacion: " << code << std::endl;
        
        int pc_anterior = reg.getPC() - 1;
        int op1 = theProgram.getOperand1(pc_anterior);
        int op2 = theProgram.getOperand2(pc_anterior);
        std::cout << "Operandos: (" << op1 << ", " << op2 << ")" << std::endl;
        
        // ===== EXECUTE =====
        std::cout << "\n--- EXECUTE ---" << std::endl;
        execute(code, op1, op2);
        
        // ===== MOSTRAR TODOS LOS REGISTROS =====
        std::cout << "\n--- ESTADO DE REGISTROS ---" << std::endl;
        reg.display();
        
        if (code == 51) break;
    }
    
    std::cout << "\n=== PROGRAMA FINALIZADO ===" << std::endl;
}

void CU::displayRegistros() const {
    reg.display();
}
