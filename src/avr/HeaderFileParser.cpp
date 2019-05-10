#include "HeaderFileParser.h"

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

std::vector<std::string> HeaderFileParser::listDefines()
{
    std::vector<std::string> keys;
    for(auto & item : defines)
    {
        keys.push_back(item.first);
    }
    return keys;
}

int HeaderFileParser::resolveSFR_IO8(int val)
{
    return val + 0x20;
}

int HeaderFileParser::resolveSFR_IO16(int val)
{
    return val + 0x20;
}
