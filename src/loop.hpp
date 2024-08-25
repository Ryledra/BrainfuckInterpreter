#pragma once

#include <iostream>
#include "loopStack.hpp"
#include "memory.hpp"

class Loop  {
    private:
        bool doStep(char c, int i, Memory* mem);
        bool validChar(char c);
        int readInput();
        bool isValid(std::string script);
        int matchLoopClose(int i);
        
        int jumpLocation {};
        std::string script;
        LoopStack loopLocation {};

    public:
        Loop();
        Loop(std::string script);
        void setScript(std::string script);
        void runScript();
};