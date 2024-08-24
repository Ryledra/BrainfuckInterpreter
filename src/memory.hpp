#pragma once

#include <vector>

class Memory
{
    private:
        static const int stackSize { 30000 };
        // int memory [stackSize] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        std::vector<unsigned char> memory { 0 };
        int pointer { 0 };

    public:
        void print();
        void printValue();
        void incMemory();
        void decMemory();
        void writeMemory(int value);
        void pointerUP();
        void pointerDOWN();
        int getMemValue();
};