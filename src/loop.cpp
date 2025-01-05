#include "loop.hpp"
#include <iostream>

Loop::Loop()    {};

Loop::Loop(char * script)   {
    Loop::script = script;
}

void Loop::setScript(char * script)    {
    Loop::script = script;
}

// returns true if jumpLocation set, else returns false for continue.
bool Loop::doStep(char c, int i, Memory* mem){
    switch (c)  {
        case '<':
            mem->pointerDOWN();
            break;
        case '>':
            mem->pointerUP();
            break;
        
        case '[':
            if (mem->getMemValue() == 0)  {
                jumpLocation = matchLoopClose(i);
                return true;
            }
            loopLocation.push_back(i);
            break;
        case ']':
            if (mem->getMemValue() > 0)   {
                jumpLocation = loopLocation.back();
                return true;
            }
            loopLocation.pop_back();
            break;
        case '+':
            mem->incMemory();
            break;
        case '-':
            mem->decMemory();
            break;
        
        case '.':
            mem->printValue();
            break;
        case ',':
            mem->writeMemory( getchar() );
            break;
    }
    return false;
};

void Loop::runScript(bool debug) {
    if ( !isValid(script) ) return;

    Memory mem {debug};
    int i {0};
    while (script[i] != '\0')   {
        if (validChar(script[i]) && doStep(script[i], i, &mem)) {
            i = jumpLocation;
        }
        i++;
    }
}

bool Loop::validChar(char c)  {
    return c == '<' || c == '>' || c == '[' || c == ']' || 
        c == '+' || c == '-' || c == '.' || c == ',';
}

bool Loop::isValid(char * script)  {
    int openCount {0};
    int closeCount {0};

    int i {0};
    while (script[i] != '\0')  {
        if (script[i] == '[') openCount++;
        if (script[i] == ']') closeCount++;

        if (closeCount > openCount) {
            std::cout << "Error: unmatched ']'";
            return false;
        }
        i++;
    }
    if (openCount > closeCount) {
        std::cout << "Error: unmatched '['";
        return false;
    }
    return true;
}

int Loop::matchLoopClose(int i)   {
    int loopsOpened {0};
    int loopsClosed {0};

    while (loopsClosed <= loopsOpened)  {
        ++i;
        if (script[i] == '[') ++loopsOpened;
        if (script[i] == ']') ++loopsClosed;
    }

    return i;
}