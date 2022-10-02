#include "Lexer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char** argv) {

    // check command line arguments
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << endl;
        return 1;
    }

    // open file
    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        cout << "File " << fileName << " could not be found or opened." << endl;
        return 1;
    }

    Lexer* lexer = new Lexer();

    //Token* token;

    // TODO

    ifstream in;
    in.open(*(argv+1));
    char c;
    string inputString;

    while (true) {
        if (in.eof())
            break;
        c = in.get();
        inputString += c;
    }
    //cout << inputString << endl;
    lexer->Run(inputString);
    cout << *lexer;
   

    in.close();


    delete lexer;

    return 0;
}
