#include "readFile.hpp"
#include <fstream>
#include <filesystem>

char* readFile::file_contents(const char * str_path)
{
    // Sanity check
    std::filesystem::path path {str_path};
    if (!std::filesystem::is_regular_file(path))
        return { };

    // Open the file
    // Note that we have to use binary mode as we want to return a string
    // representing matching the bytes of the file on the file system.
    std::ifstream file(path, std::ios::in | std::ios::binary);
    if (!file.is_open())
        return { };

    // Read contents
    char * content = (char*)malloc(sizeof(char) * (file.gcount() + 1));
    int i { 0 };
    while (file.get(content[i])) i++;
    content[i] = '\0';

    // Close the file
    file.close();

    return content;
}