#include "EOFTypeAutomaton.h"

void EOFTypeAutomaton::S0(const std::string& input) {
    if (input[index] == '\377') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}