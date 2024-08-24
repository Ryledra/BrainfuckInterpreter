#pragma once

class Memory
{
    private:
        static const int STACKSIZE { 30000 };
        unsigned char* memoryStart {};
        unsigned char* pointer {};
        int memoryUsed { 0 };

    public:
        Memory();
        void debugPrint();
        void printValue();
        void incMemory();
        void decMemory();
        void writeMemory(int value);
        void pointerUP();
        void pointerDOWN();
        int getMemValue();
};