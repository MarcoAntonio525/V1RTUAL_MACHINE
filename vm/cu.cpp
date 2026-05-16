cat > CU.cpp << 'EOF'
#include "CU.hpp"
#include <iostream>

CU::CU() : status("idle") {}

CU::CU(std::string theStatus) : status(theStatus) {}

Instruccion CU::fetch(Program& theProgram)
{
    int pc_actual = reg.getPC();
    std::cout << "[DEBUG fetch] PC actual = " << pc_actual << std::endl;
    
    reg.setMAR(pc_actual);
    Instruccion inst = theProgram.getInstruction(pc_actual);
    reg.setMBR(inst.getCode());
    reg.setIR(reg.getMBR());
    
    int nuevo_pc = pc_actual + 1;
    reg.setPC(nuevo_pc);
    std::cout << "[DEBUG fetch] Nuevo PC = " << nuevo_pc << std::endl;
    
    return inst;
}

int CU::decode(const Instruccion& theInstruction)
{
    std::string name = theInstruction.getName();
    std::cout << "[DEBUG decode] Instruccion: " << name << std::endl;
    
    if (name == "START") return 50;
    if (name == "STOP") return 51;
    if (name == "ADD") return 80;
    if (name == "SUB") return 81;
    if (name == "MUL") return 82;
    if (name == "DIV") return 83;
    if (name == "MOV") return 90;
    if (name == "STO") return 91;
    
    std::cout << "Error: Instrucción '" << name << "' no reconocida" << std::endl;
    return -1;
}

void CU::execute(int theCode, int operand1, int operand2)
{
    int result;
    
    switch (theCode)
    {
        case 50:
            std::cout << "=== INICIO DEL PROGRAMA ===" << std::endl;
            status = "running";
            break;
        case 51:
            std::cout << "=== FIN DEL PROGRAMA ===" << std::endl;
            status = "stopped";
            break;
        case 80:
            result = alu.add(operand1, operand2);
            reg.setAC(result);
            std::cout << "ADD: " << operand1 << " + " << operand2 << " = " << result << std::endl;
            break;
        case 81:
            result = alu.sub(operand1, operand2);
            reg.setAC(result);
            std::cout << "SUB: " << operand1 << " - " << operand2 << " = " << result << std::endl;
            break;
        case 82:
            result = alu.mul(operand1, operand2);
            reg.setAC(result);
            std::cout << "MUL: " << operand1 << " * " << operand2 << " = " << result << std::endl;
            break;
        case 83:
            if (operand2 != 0) {
                result = alu.div(operand1, operand2);
                reg.setAC(result);
                std::cout << "DIV: " << operand1 << " / " << operand2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division entre cero" << std::endl;
            }
            break;
        case 90:
            reg.setAL(operand1);
            std::cout << "MOV: AL = " << operand1 << std::endl;
            break;
        case 91:
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
    std::cout << "[DEBUG] Tamaño del programa: " << theProgram.getSize() << std::endl;
    
    while (status == "running" && reg.getPC() < theProgram.getSize())
    {
        std::cout << "\n========== INICIO CICLO ==========" << std::endl;
        std::cout << "[DEBUG] PC al inicio del ciclo: " << reg.getPC() << std::endl;
        std::cout << "[DEBUG] Status: " << status << std::endl;
        
        std::cout << "\n--- FETCH ---" << std::endl;
        Instruccion inst = fetch(theProgram);
        std::cout << "PC despues de fetch: " << reg.getPC() << std::endl;
        std::cout << "IR: " << reg.getIR() << " (Instruccion: " << inst.getName() << ")" << std::endl;
        
        std::cout << "\n--- DECODE ---" << std::endl;
        int code = decode(inst);
        std::cout << "Codigo de operacion: " << code << std::endl;
        
        int pc_anterior = reg.getPC() - 1;
        int op1 = theProgram.getOperand1(pc_anterior);
        int op2 = theProgram.getOperand2(pc_anterior);
        std::cout << "Operandos: (" << op1 << ", " << op2 << ")" << std::endl;
        
        std::cout << "\n--- EXECUTE ---" << std::endl;
        execute(code, op1, op2);
        
        std::cout << "\n--- ESTADO DE REGISTROS ---" << std::endl;
        reg.display();
        
        std::cout << "[DEBUG] PC al final del ciclo: " << reg.getPC() << std::endl;
        std::cout << "[DEBUG] Status al final: " << status << std::endl;
        
        if (code == 51) {
            std::cout << "[DEBUG] Break por STOP" << std::endl;
            break;
        }
    }
    
    std::cout << "\n=== PROGRAMA FINALIZADO ===" << std::endl;
}

void CU::displayRegistros() const {
    reg.display();
}
EOF
