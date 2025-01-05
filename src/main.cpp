#include <iostream>

#include "readFile.hpp"
#include "loop.hpp"

void help() {
    std::cout << "Ryledra's Brainfuck Interpreter\n"
        << "A CLI application to run brainfuck code. Brainfuck code\n"
        << "can be provided in either in-line or file format.\n\n"
        << "Usage:\n  Brainfuck [options] [*brainfuck code]\n\n"
        << "Flags:\n  -f, --file\t indicates the following filepath holds the code\n"
        << "  -d, --debug\t all prints will be output as integer values on separate lines\n";
}

int main(int argc, char *argv[])  {
    if (argc == 1)  {
        help();
        return 0;
    }
    if (argc > 4)  {
        std::cout << "Error: Wrong number of arguments.\n\n";
        help();
        return 1;
    }
    Loop l = {};
    bool debug {false};
    if (argc == 2)  {
        l.setScript(argv[1]);
    }
    else if (argc >= 3) {
        for(int i = 1; i < argc; i++)   {
            if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0)    {
                l.setScript( readFile::file_contents(argv[i+1]) );
                i++;
            } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--debug") == 0)    {
                debug = true;
            } 
            else  {
                l.setScript( argv[i] );
            }
        }
    }
    l.runScript(debug);
    std::cout << '\n';
    
    return 0;
}