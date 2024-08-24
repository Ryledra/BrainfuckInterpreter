#pragma once

#include <filesystem>
#include <fstream>

namespace readFile  {
    std::string file_contents(const std::filesystem::path& path);
}