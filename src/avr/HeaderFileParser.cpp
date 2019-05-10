#include "HeaderFileParser.h"
#include <iostream>
//Instance fpr singleton
std::shared_ptr<HeaderFileParser> HeaderFileParser::parserInstance;

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
            if(splitted.size() > 2)
                defines.insert({splitted[1],splitted[2]});
        }
    }
    file.close();
}

int HeaderFileParser::processDefine(std::string define)
{
    if(defines.find(define) != defines.end())
    {
        std::string def = defines[define];
        std::vector<std::string> strs;
        boost::split(strs, def, boost::is_any_of("("));
        if(def.find("_SFR_IO8") != std::string::npos)
        {
            std::string number = strs[1];
            int val = std::stoi(number);
            val = resolveSFR_IO8(val);
            return val;
        }
        else  if(def.find("_SFR_IO16") != std::string::npos)
        {
            std::string number = strs[1];
            int val = std::stoi(number);
            val = resolveSFR_IO16(val);
            return val;
        }
        else if(def.find("_VECTOR") != std::string::npos)
        {
            std::string number = strs[1];
            int val = std::stoi(number);
            return val;
        }
        try {
            int val = std::stoi(def);
            return val;
        } catch (std::invalid_argument &ex) {

        }
    }
    return -1;
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

void HeaderFileParser::initInstance(std::string _file)
{
    if(!parserInstance)
        parserInstance = std::make_shared<HeaderFileParser>(_file);
}

std::shared_ptr<HeaderFileParser> HeaderFileParser::instance()
{
    return parserInstance;
}


int HeaderFileParser::resolveSFR_IO8(int val)
{
    return val + 0x20;
}

int HeaderFileParser::resolveSFR_IO16(int val)
{
    return val + 0x20;
}
