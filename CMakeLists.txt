cmake_minimum_required(VERSION 3.23)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(project1submit)

add_executable(project_1
        CommentAutomaton.cpp
        CommentAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        FactsAutomaton.h
        FactsAutomaton.cpp
        RulesAutomaton.cpp
        RulesAutomaton.h
        SchemesAutomaton.h
        SchemesAutomaton.cpp
        IdAutomaton.cpp
        IdAutomaton.h
        QueriesAutomaton.cpp
        QMarkAutomaton.h
        UndefinedAutomaton.cpp
        UndefinedAutomaton.h
        EOFTypeAutomaton.cpp
        EOFTypeAutomaton.h
        Automaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        AddAutomaton.cpp
        AddAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QMarkAutomaton.cpp
        QMarkAutomaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h)
