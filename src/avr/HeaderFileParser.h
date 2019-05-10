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
    /**
     * @brief HeaderFileParser
     * @param _file - path to the header file
     */
    HeaderFileParser(std::string _file);

    /**
     * @brief parse - needs to be called first. Reads the headerfile and stores it in a map
     */
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
    /**
     * @brief getDefine - retrieve a define
     * @param define - the name of the define
     * @param process - if true the define is passed to an internal process method. This method extracts the define
     * _VECTOR, _SFR_IO8 and _SFR_IO16. In case of _SFR_IO8 and _SFR_IO16 0x20 is added to the address to convert it into the global address space
     * @return integer value behind the define
     * @throws std::bad_cast
     */
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
    /**
     * @brief listDefines
     * @return list containing names of all defines
     */
    std::vector<std::string> listDefines();
private:
    std::string header_path;


    std::map<std::string, std::string> defines;

    int resolveSFR_IO8(int val);
    int resolveSFR_IO16(int val);
    int processDefine(std::string define);

};

#endif // HEADERFILEPARSER_H
