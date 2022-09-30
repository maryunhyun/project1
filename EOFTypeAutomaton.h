#ifndef EOFTYPEAUTOMATON_H
#define EOFTYPEAUTOMATON_H

#include "Automaton.h"

class EOFTypeAutomaton : public Automaton
{
public:
    EOFTypeAutomaton() : Automaton(TokenType::EOF_type) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // EOFTypeAUTOMATON_H

