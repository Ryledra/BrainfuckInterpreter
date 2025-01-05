#pragma once

#include "loopStack.hpp"
#include "memory.hpp"

class Loop  {
    private:
        bool doStep(char c, int i, Memory* mem);
        bool validChar(char c);
        bool isValid(char * script);
        int matchLoopClose(int i);
        
        int jumpLocation {};
        char * script;
        LoopStack loopLocation {};

    public:
        Loop();
        Loop(char * script);
        void setScript(char * script);
        void runScript(bool debug);
};