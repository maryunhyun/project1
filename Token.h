#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    EOF_type,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    string description;
    int line;



public:
    Token(TokenType type, string description, int line);

    string toString();

    friend ostream& operator<< (ostream& os, Token& token) {
        os << token.toString();
        return os;
    }
    string enumToString() ;
    // TODO: add other needed methods
};

#endif // TOKEN_H

