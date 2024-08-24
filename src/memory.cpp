#include "memory.hpp"
#include <iostream>

void Memory::print()    {
    std::cout << '\n';
    for (int i { 0 }; i < memory.size(); ++i)   {
        std::cout << memory[i] << ',';
    }
    std::cout << '\n';
}

void Memory::printValue()   {
    std::cout << char(memory[pointer]);
}

void Memory::incMemory()    {
    memory[pointer]++;
}

void Memory::decMemory()    { 
    memory[pointer]--; 
}

void Memory::writeMemory(int value)    {
    memory[pointer] = value;
}

void Memory::pointerUP()    { 
    if (pointer == stackSize-1) std::exit(EXIT_FAILURE);
    if (pointer + 2 > memory.size())    {
        memory.push_back(0);
    }
    pointer++;
}

void Memory::pointerDOWN()  { 
    if (pointer == 0) std::exit(EXIT_FAILURE);
    pointer--; 
}

int Memory::getMemValue()   {
    return memory[pointer];
}