#include <iostream>
#include <stdlib.h>
#include "Instruccion.hpp"
#include "InstruccionSet.hpp"
#include "Program.hpp"
#include "CU.hpp"
#include "ALU.hpp"
#include "Registros.hpp"    // ← NUEVO

using namespace std;

int main(void)
{
    cout << "=== MAQUINA VIRTUAL CON REGISTROS ===" << endl << endl;
    
    // Crear instrucciones
    Instruccion start("START", 50, 0);
    Instruccion add("ADD", 80, 2);
    Instruccion sub("SUB", 81, 2);
    Instruccion mul("MUL", 82, 2);
    Instruccion div("DIV", 83, 2);
    Instruccion mov("MOV", 90, 2);
    Instruccion sto("STO", 91, 2);
    Instruccion stop("STOP", 51, 0);
    
    // Cargar programa
    Program program;
    program.addInstruction(start, 0, 0);
    program.addInstruction(mov, 50, 0);      // MOV AL, 50
    program.addInstruction(mov, 30, 0);      // MOV AL, 30
    program.addInstruction(add, 50, 30);     // ADD 50 + 30
    program.addInstruction(sub, 100, 40);    // SUB 100 - 40
    program.addInstruction(mul, 5, 6);       // MUL 5 * 6
    program.addInstruction(div, 100, 4);     // DIV 100 / 4
    program.addInstruction(sto, 80, 200);    // STO 200, 80
    program.addInstruction(stop, 0, 0);
    
    // Mostrar programa
    cout << "Programa cargado (" << program.getSize() << " instrucciones):" << endl;
    for (int i = 0; i < program.getSize(); i++) {
        cout << "  " << i << ": " << program.getInstruction(i).getName();
        if (program.getOperand1(i) != 0 || program.getOperand2(i) != 0) {
            cout << " (" << program.getOperand1(i) << ", " << program.getOperand2(i) << ")";
        }
        cout << endl;
    }
    
    // Ejecutar programa
    cout << "\n=== EJECUTANDO PROGRAMA ===" << endl;
    CU unidadControl;
    unidadControl.run(program);
    
    return EXIT_SUCCESS;
}