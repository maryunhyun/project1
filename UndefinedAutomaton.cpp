#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const string& input) {
    if (input[index] != '#' && input[index] != '\'') {
        inputRead++;
        S7(input);
    }

    else if (input[index] == '#') {
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        numApostrophes++;
        S4(input);
    }
    else {
        Serr();
    }

}
void UndefinedAutomaton::S2(const string& input) {
    if (input[index] == '\n') {
        newLines++;
    }
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S3(const string& input) {
    while (input[index] != '|') {
        if (input[index] == '\n') {
            newLines++;
        }
        if (input[index] == EOF) {
            S7(input);
            break;
        }
        inputRead++;
        index++;

    }
    if (input[index] == '|') {
        inputRead++;
        index++;
        S5(input);

    }
}
void UndefinedAutomaton::S4(const string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        numApostrophes++;
        S6(input);
    }
    while (input[index] != '\'') {
        if (input[index] == '\n') {
            newLines++;
            int remainApostrophesDiv = numApostrophes % 2;
            if (remainApostrophesDiv == 0 && numApostrophes != 0) {
                Serr();
            }
        }
        else if (input[index] == EOF) {
            S7(input);
            break;
        }
        inputRead++;
        index++;
        if (input[index] == '\'') {
            inputRead++;
            index++;
            numApostrophes++;
            S6(input);
        }
    }
}

void UndefinedAutomaton::S5(const string& input) {
    if (input[index] == '#') {
        inputRead++;
        S7(input);
    }
    else {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S3(input);
    }
}


void UndefinedAutomaton::S6(const string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        numApostrophes++;
        S4(input);
    }
    while (input[index] != '\'') {
        if (input[index] == '\n') {
            newLines++;
            int remainApostrophesDiv = numApostrophes % 2;
            if (remainApostrophesDiv == 0 && numApostrophes != 0) {
                Serr();
            }
        }
        else if (input[index] == EOF) {
            S7(input);
            break;
        }
        inputRead++;
        index++;
        if (input[index] == '\'') {
            inputRead++;
            index++;
            numApostrophes++;
            S4(input);
        }
    }
}

void UndefinedAutomaton::S7(const string& input) {
    int remainApostrophesDiv = numApostrophes % 2;
    if (remainApostrophesDiv == 0 && numApostrophes != 0) {
        Serr();
    }
}