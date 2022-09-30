#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "EOFTypeAutomaton.h"
#include "UndefinedAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "CommentAutomaton.h"
#include "StringAutomaton.h"
#include <iostream>
#include <sstream>

using namespace std;
Token* token;
int numTokens = 0;
CommentAutomaton commentAutomaton;



Lexer::Lexer() {
    CreateAutomata();

}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    /*for (int i = 0; i < automata.size(); i++) {
        delete automata[i];
    }
    for (int i = 0; i < tokens.size(); i++) {
        delete tokens[i];
    }*/
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new EOFTypeAutomaton());
    // TODO: Add the other needed automata here
}
//read out from tokens vector
string Lexer::toString() {
    ostringstream output;
    int tokensSize = tokens.size();

    for (int i = 0; i < tokensSize; i++) {
        output << tokens[i]->toString();
    }
    output << "Total Tokens = " << tokensSize;
    string testing = output.str();
    return output.str();
}


void Lexer::Run(string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    int inputRead = 0;
    int maxRead;
    int automataSize = automata.size();

    string tokString;
    Token* newToken;
    Automaton* maxAutomaton;

    while (input.size() > 0) {
        if (input[0] == EOF) {
            input.erase(0,1);
            break;
        }
        maxRead = 0;
        maxAutomaton = automata[0];


        while (input[0] == '\n' || input[0] == '\r' || input[0] == ' ' || input[0] == '\t') {
            if (input[0] == '\n') {
                lineNumber++;
            }
            input.erase(0,1);
        }


        //"Parallel" part
        for (int i = 0; i < automataSize; i++) {
            inputRead = automata[i]->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
            }
        }

        if (maxRead > 0) {
            if (input[0] == EOF) break;
            tokString = input.substr(0,maxRead);
            newToken = maxAutomaton->CreateToken(tokString, lineNumber);
            lineNumber = maxAutomaton->NewLinesRead() + lineNumber;
            tokens.push_back(newToken);
        }

        else {
            if (input[0] == EOF) {
                //input.erase(0,1);
                break;
            }
            maxRead = 1;
            tokString = input.substr(0,maxRead);
            //will determine within Token.cpp that it is undefined
            maxAutomaton = automata[automataSize-2];
            newToken = maxAutomaton->CreateToken(tokString, lineNumber);
            tokens.push_back(newToken);
        }

        input.erase(0,maxRead);

    }
    maxAutomaton = automata[automataSize-1];
    Token* newEOFToken = maxAutomaton->CreateToken("", lineNumber);
    tokens.push_back(newEOFToken);
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}
