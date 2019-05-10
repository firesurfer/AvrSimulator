#include "HeaderFileParser.h"
#include <iostream>
int main(int argc, char** argv)
{
    std::string path = argv[1];
    HeaderFileParser parser(path);
    parser.parse();

    std::vector<std::string> defines = parser.listDefines();

    for(auto & define: defines)
    {
        std::cout << define << " : " << parser.getDefine(define,true)<< std::endl;
    }




}
