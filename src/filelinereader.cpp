#include "filelinereader.h"

#include <fstream>

std::vector<std::string> GetFileLines(const std::string& path)
{
    std::ifstream ifs(path.c_str());
    if (!ifs.is_open())
        throw std::string("Failed to open file!");

    std::vector<std::string> result;
    while (!ifs.eof())
    {
        std::string line;
        std::getline(ifs, line);
        result.push_back(line);
    }

    return result;
}
