#include "CommentAutomaton.h"


void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        if (input[index] == '|') {
            S1(input);
        }
        //made separate state for while loop instead
        else if (input[index] != '\n' && input[index] != EOF) {
            inputRead++;
            index++;
            S5(input);
        }
        else if (input[index] == '\n' || input[index] == EOF) {
            if (input[index] == '\n') {
                newLines++;
            }
            S4(input);
        }

    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}


void CommentAutomaton::S2(const std::string& input) {
    if (input[index] == EOF) {
        Serr();
    }
    while (input[index] != '|') {
        if (input[index] == EOF) {
            Serr();
            break;
        }
        else if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
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

void CommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S4(const std::string& input) {
    //supposed to be blank

}
//state to continue through comment and to be like a while loop
void CommentAutomaton::S5(const std::string& input) {
    if (input[index] != '\n' && input[index] != EOF) {
        inputRead++;
        index++;
        S6(input);
    }
    else if (input[index] == '\n' || input[index] == EOF) {
        /*if (input[index] == '\n') {
            newLines++;
        }*/
        S4(input);

    }
    else {
        Serr();
    }

}

void CommentAutomaton::S6(const std::string& input) {
    if (input[index] != '\n' && input[index] != EOF) {
        inputRead++;
        index++;
        S5(input);
    }
    else if (input[index] == '\n' || input[index] == EOF) {
        /*if (input[index] == '\n') {
            newLines++;
        }*/
        S4(input);
    }

    else {
        Serr();
    }

}




