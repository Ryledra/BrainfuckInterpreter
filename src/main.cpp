#include <iostream>

#include "readFile.hpp"
#include "loop.hpp"

int main(int argc, char *argv[])  {

    if (argc == 2)  {
        std::filesystem::path path { argv[1] };
        Loop l { readFile::file_contents(path) };
        l.runScript();
    } else  {
        std::cout << "Error: Wrong number of arguments. Expected 1 file-path argument, recieved " << argc-1 << ".\n";
    }
    
    return 0;
}