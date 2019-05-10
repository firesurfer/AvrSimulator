#ifndef HEADERFILEPARSER_H
#define HEADERFILEPARSER_H

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
class HeaderFileParser
{
public:
    HeaderFileParser(std::string _file);

    void parse();

    template<typename T>
    T getDefine(std::string define)
    {
        if(defines.find(define) != defines.end())
        {
            return defines[define];
        }
        return "";
    }
    int getDefine(std::string define)
    {

        if(defines.find(define) != defines.end())
        {
            return std::stoi(defines[define]);
        }
        return -1;
    }
    int processDefine(std::string define)
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

        }
        return -1;
    }
    std::vector<std::string> listDefines();
private:
    std::string header_path;


    std::map<std::string, std::string> defines;

    int resolveSFR_IO8(int val);
    int resolveSFR_IO16(int val);

};

#endif // HEADERFILEPARSER_H
