#include "StringAutomaton.h"


void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        numApostrophes++;
        if (input[index] == EOF) {
            Serr();
        }
        else if (input[index] != EOF) {
            S1(input);
        }
    }
    else {
        Serr();
    }

}

void StringAutomaton::S1(const std::string& input) {
    if (input[index] != '\'') {
        if (input[index] == EOF) {
            Serr();
        }
        else if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        if (input[index] == EOF) {
            Serr();
        }
        else if (input[index] != EOF) {
            S2(input);
        }
    }

    else if (input[index] == '\'') {
        inputRead++;
        index++;
        numApostrophes++;

        if (input[index] == '\'') {
            inputRead++;
            index++;
            numApostrophes++;
            S2(input);
        }
        else {
            S3(input);
        }

    }

    else {
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] != '\'') {
        if (input[index] == EOF) {
            Serr();
        }

        if (input[index] == EOF) {
            Serr();
        }
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        if (input[index] != EOF) {
            S1(input);
        }
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        numApostrophes++;

        if (input[index] == '\'') {
            inputRead++;
            index++;
            numApostrophes++;
            S1(input);
        }
        else {
            S3(input);
        }
    }

    else {
        Serr();
    }

}


void StringAutomaton::S3(const std::string& input) {
    int remainApostrophesDiv = numApostrophes % 2;
    if (remainApostrophesDiv != 0) {
        Serr();
    }
    else {
        S4(input);
    }
}
void StringAutomaton::S4(const std::string& input) {
    //supposed to be blank
}




