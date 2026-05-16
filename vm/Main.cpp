cat > Main.cpp << 'EOF'
#include <iostream>
#include <stdlib.h>
#include "Instruccion.hpp"
#include "InstruccionSet.hpp"
#include "Program.hpp"
#include "CU.hpp"
#include "ALU.hpp"
#include "Registros.hpp"

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
    program.addInstruction(start, 0, 0);   // 0: START
    program.addInstruction(mov, 5, 0);     // 1: MOV AL, 5
    program.addInstruction(mov, 3, 0);     // 2: MOV AL, 3
    program.addInstruction(add, 5, 3);     // 3: ADD 5 + 3
    program.addInstruction(sub, 10, 4);    // 4: SUB 10 - 4
    program.addInstruction(mul, 2, 3);     // 5: MUL 2 * 3
    program.addInstruction(div, 20, 2);    // 6: DIV 20 / 2
    program.addInstruction(sto, 100, 200); // 7: STO 100 en dir 200
    program.addInstruction(stop, 0, 0);    // 8: STOP

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
EOF
