#pragma once

class LoopStack {
    private:
        static const int STACKSIZE { 20 };
        int* stackStart {};
        int stackDepth { 0 };

    public:
        LoopStack();
        void push_back(int location);
        int back();
        int pop_back();
};