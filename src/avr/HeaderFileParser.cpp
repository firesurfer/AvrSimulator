#include "HeaderFileParser.h"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
HeaderFileParser::HeaderFileParser(std::string _file):
    header_path(_file)
{

}

void HeaderFileParser::parse()
{
    if(!boost::filesystem::exists(header_path))
    {
        throw std::runtime_error("Given headerfile does not exist");
    }

    std::ifstream file(header_path);
    if(!file.is_open())
        throw std::runtime_error("Could not open headerfile: " + header_path);

    std::string line ="";
    while (std::getline(file, line))
    {
        if(line.find("#define") != std::string::npos)
        {
            std::vector<std::string> splitted;
            boost::split(splitted,line, boost::is_any_of("\t "),boost::token_compress_on);
            defines.insert({splitted[0],splitted[1]});
        }
    }
}
