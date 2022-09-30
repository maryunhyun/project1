#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    while (isalpha(input[index]) || isdigit(input[index])) {
        inputRead++;
        index++;
    }

    if (!isalpha(input[index]) && !isdigit(input[index])) {
        S2(input);
    }

    else {
        Serr();
    }
}

void IdAutomaton::S2(const std::string& input) {
    //supposed to be empty
}

