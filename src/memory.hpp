#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <iostream>
#include <vector>

class Memory
{
    private:
        static const int stackSize { 20 };
        // int memory [stackSize] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        //                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        std::vector<int> memory { 0 };
        int pointer { 0 };

    public:
        void print()    {
            std::cout << '\n';
            for (int i { 0 }; i < memory.size(); ++i)   {
                std::cout << memory[i] << ',';
            }
            std::cout << '\n';
        }

        void printValue()   { std::cout << char(memory[pointer]); };

        void incMemory()    { memory[pointer]++; };

        void decMemory()    { memory[pointer]--; };

        void writeMemory(int value)    { memory[pointer] = value; };

        void pointerUP()    { 
            // std::cout << pointer << ' ' << memory.size();
            if (pointer + 2 > memory.size())    {
                memory.push_back(0);
                // print();
            }
            pointer = (pointer + 1) % memory.size();
        };

        void pointerDOWN()  { pointer = (pointer - 1) % memory.size(); };

        int getMemValue()   { return memory[pointer]; };
};

#endif