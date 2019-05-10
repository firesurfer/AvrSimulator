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
    T getDefine(std::string define, bool process = true)
    {
        if(defines.find(define) != defines.end())
        {
            return defines[define];
        }
        return "";
    }
    int getDefine(std::string define, bool process = true)
    {
        if(defines.find(define) != defines.end())
        {
            if(process)
            {
                return processDefine(define);
            }
            else {
                return std::stoi(defines[define]);
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
    int processDefine(std::string define);

};

#endif // HEADERFILEPARSER_H
