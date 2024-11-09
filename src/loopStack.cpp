#include <iostream>
#include "loopStack.hpp"

LoopStack::LoopStack()  {
    stackStart = (int*)malloc(sizeof(int) * STACKSIZE);
}

void LoopStack::push_back(int location) {
    if (stackDepth == STACKSIZE)    {
        std::cout << "Loop depth exceeds maximum: " << STACKSIZE << '\n';
        std::exit(EXIT_FAILURE);
    }
    stackDepth++;
    *(stackStart + (stackDepth - 1)) = location;
}

int LoopStack::back()   {
    return *(stackStart + (stackDepth - 1));
}
int LoopStack::pop_back()   {
    stackDepth--;
    return *(stackStart + (stackDepth));
}