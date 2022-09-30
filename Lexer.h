#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

using namespace std;

class Lexer
{
private:
    vector<Automaton*> automata;
    vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();


    void Run(std::string& input);

    // TODO: add other public methods here
    //make sure to dereference Lexer
    //output string with this and token should already be set up and ready in Token toString()
    string toString();

    friend ostream& operator<< (ostream& os, Lexer& lexer) {
        os << lexer.toString();
        return os;
    }

};

#endif // LEXER_H

