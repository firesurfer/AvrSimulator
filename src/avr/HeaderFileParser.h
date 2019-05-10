#ifndef HEADERFILEPARSER_H
#define HEADERFILEPARSER_H

#include <string>
#include <algorithm>
#include <vector>
#include <map>
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
    std::vector<std::string> listDefines();
private:
    std::string header_path;


    std::map<std::string, std::string> defines;

};

#endif // HEADERFILEPARSER_H
