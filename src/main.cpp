#include <iostream>

#include "readFile.hpp"
#include "loop.hpp"

void help() {
    std::cout << "Ryledra's Brainfuck Interpreter\n"
        << "A CLI application to run brainfuck code. Brainfuck code\n"
        << "can be provided in either in-line or file format.\n\n"
        << "Usage:\n  Brainfuck [options] [*brainfuck code]\n\n"
        << "Flags:\n  -f, --file\t indicates the following filepath holds the code\n";
}

int main(int argc, char *argv[])  {
    if (argc == 1)  {
        help();
        return 0;
    }
    if (argc > 3)  {
        std::cout << "Error: Wrong number of arguments.\n\n";
        help();
        return 1;
    }
    Loop l = {};
    if (argc == 2)  {
        l.setScript(argv[1]);
    }
    else if (argc == 3) {
        if (!(strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0))    {
            std::cout << "Option flag `" << argv[1] << "`not recognised.\n\n";
            help();
            return 1;
        }

        //std::filesystem::path path { argv[2] };
        l.setScript( readFile::file_contents(argv[2]) );
    }
    l.runScript();
    std::cout << '\n';
    
    return 0;
}