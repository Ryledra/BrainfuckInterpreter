#include "memory.hpp"
#include <iostream>

void Memory::debugPrint()    {
    pointer = memoryStart;
    for (int i { 0 }; i < memoryUsed; ++i)   {
        Memory::printValue();
        Memory::pointerUP();
    }
    std::cout << '\n';
}

Memory::Memory()    {
    memoryStart = (unsigned char*)malloc(STACKSIZE);
    pointer = memoryStart;
    (*pointer) = 0;
    memoryUsed++;
}

void Memory::printValue()   {
    std::cout << char(*pointer);
}

void Memory::incMemory()    {
    // if((*pointer) == (unsigned char)255) (*pointer) = (unsigned char)0;
    (*pointer)++;
}

void Memory::decMemory()    { 
    // if((*pointer) == (unsigned char)0) (*pointer) = (unsigned char)256;
    (*pointer)--; 
}

void Memory::writeMemory(int value)    {
    (*pointer) = value;
}

void Memory::pointerUP()    { 
    if (pointer - memoryStart == STACKSIZE) std::exit(EXIT_FAILURE);
    if (pointer - memoryStart > memoryUsed)    {
        *(pointer+1) = (unsigned char)0;
        memoryUsed++;
    }
    pointer++;
}

void Memory::pointerDOWN()  { 
    if (pointer == memoryStart) {
        std::cout << "Attempted to access memory lower than start\n";
        // Memory::debugPrint();
        std::exit(EXIT_FAILURE);
    }
    pointer--; 
}

int Memory::getMemValue()   {
    return *pointer;
}