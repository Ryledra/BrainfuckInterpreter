#include "loop.hpp"

Loop::Loop(std::string script)   {
    Loop::script = script;
}

// returns true if jumpLocation set, else returns false for continue.
bool Loop::doStep(char c, int i, Memory* mem){
    switch (c)  {
        case '<':
            (*mem).pointerDOWN();
            break;
        case '>':
            (*mem).pointerUP();
            break;
        
        case '[':
            if ((*mem).getMemValue() == 0)  {
                jumpLocation = matchLoopClose(i);
                return true;
            }
            loopLocation.push_back(i);
            //loopCount.push_back((*mem).getMemValue());
            break;
        case ']':
            if ((*mem).getMemValue() > 0)   {
                jumpLocation = loopLocation.back();
                return true;
            }
            loopLocation.pop_back();
            break;
        case '+':
            (*mem).incMemory();
            break;
        case '-':
            (*mem).decMemory();
            break;
        
        case '.':
            (*mem).printValue();
            break;
        case ',':
            (*mem).writeMemory(readInput());
            break;
    }
    return false;
};

void Loop::runScript() {
    if ( !isValid(script) ) return;
    // std::cout << "is valid";

    Memory mem {};
    for (int i {0}; i < script.length(); ++i)    {
        // mem.print();
        if (validChar(script[i]))   {
            if(doStep(script[i], i, &mem)) {
                i = jumpLocation;
            }
        }
    }
}

bool Loop::validChar(char c)  {
    if (c == '<' || c == '>' || c == '[' || c == ']' || 
        c == '+' || c == '-' || c == '.' || c == ','    ) return true;
    return false;
}

int Loop::readInput()   {
    char c {};
    std::cin >> c;
    return int(c);
}

bool Loop::isValid(std::string script)  {
    int openCount {0};
    int closeCount {0};

    for (int i {0}; i < script.length(); ++i)   {
        if (script[i] == '[') openCount++;
        if (script[i] == ']') closeCount++;

        if (closeCount > openCount) {
            std::cout << "Error: unmatched ']'";
            return false;
        }
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