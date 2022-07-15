#ifndef LOOP_HPP
#define LOOP_HPP

#include <iostream>
#include <vector>
#include "memory.hpp"

class Loop  {
    private:
        bool doStep(char c, int i, Memory* mem);
        bool validChar(char c);
        int readInput();
        bool isValid(std::string script);

        std::string script;
        int readLocation { 0 };
        //std::vector<int> loopCount {};
        std::vector<int> loopLocation {};

    public:
        Loop(std::string script);
        void runScript();
};

#endif