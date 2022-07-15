#include "loop.hpp"

Loop::Loop(std::string script)   {
    Loop::script = script;
}

bool Loop::doStep(char c, int i, Memory* mem){
    switch (c)  {
        case '<':
            (*mem).pointerDOWN();
            break;
        case '>':
            (*mem).pointerUP();
            break;
        
        case '[':
            loopLocation.push_back(i);
            //loopCount.push_back((*mem).getMemValue());
            break;
        case ']':
            if ((*mem).getMemValue() > 0)
                return true;
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
    Memory mem {};
    for (int i {0}; i < script.length(); ++i)    {
        // mem.print();
        if (validChar(script[i]))   {
            if(doStep(script[i], i, &mem)) {
                i = loopLocation.back();
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