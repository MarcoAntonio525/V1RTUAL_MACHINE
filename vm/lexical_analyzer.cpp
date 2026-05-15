#include "lexycal_analyzer.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

LexicalAnalyzer::LexicalAnalyzer() {}

std::vector<std::string> LexicalAnalyzer::tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(line);
    
    // Separar por espacios y comas
    while (std::getline(ss, token, ' ')) {
        // Eliminar comas
        token.erase(std::remove(token.begin(), token.end(), ','), token.end());
        
        // Eliminar espacios
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    
    return tokens;
}

bool LexicalAnalyzer::isNumber(const std::string& token) {
    if (token.empty()) return false;
    
    for (char c : token) {
        if (!std::isdigit(c) && c != '-' && c != '+') {
            return false;
        }
    }
    return true;
}

bool LexicalAnalyzer::isRegister(const std::string& token) {
    // Registros válidos
    std::vector<std::string> registers = {
        "AL", "AH", "BL", "BH",
        "AX", "BX", "CX", "DX",
        "PC", "IR", "MAR", "MBR", "AC"
    };
    
    for (const auto& reg : registers) {
        if (token == reg) return true;
    }
    return false;
}

std::string LexicalAnalyzer::identifyToken(const std::string& token) {
    if (isRegister(token)) {
        return "REGISTER";
    } else if (isNumber(token)) {
        return "NUMBER";
    } else {
        return "INSTRUCTION";
    }
}

int LexicalAnalyzer::getInstructionCode(const std::string& instruction) {
    if (instruction == "START") return 50;
    if (instruction == "STOP") return 51;
    if (instruction == "ADD") return 80;
    if (instruction == "SUB") return 81;
    if (instruction == "MUL") return 82;
    if (instruction == "DIV") return 83;
    if (instruction == "MOV") return 90;
    if (instruction == "STO") return 91;
    
    return -1;  // Instrucción no reconocida
}

int LexicalAnalyzer::getOperandValue(const std::string& token) {
    if (isNumber(token)) {
        return std::stoi(token);
    }
    return 0;  // Si es registro, el valor está en el banco de registros
}

std::vector<Token> LexicalAnalyzer::analyze(const std::string& line) {
    std::vector<Token> result;
    std::vector<std::string> tokens = tokenize(line);
    
    for (const auto& token : tokens) {
        Token t;
        t.value = token;
        t.type = identifyToken(token);
        result.push_back(t);
    }
    
    return result;
}