#include <string>
#include <iostream>
#include <sstream>

const static std::string delimeters="~`!@#$%^&*()-=+><,.?/|\\\"';:][{}_";

static void usage()
{
    std::cout << "Program breaks STDIN into words and prints it in STDOUT each word on new line." << std::endl;
}

static void parseStream(std::istream& in)
{
    std::string buffer;    
    while(in>>buffer)
    {
        bool had_replace = false;
        for (std::size_t found = 0;;)
        {
            found = buffer.find_first_of(delimeters, found);
            if (found == std::string::npos)
                break;
            buffer.at(found) = ' ';
            had_replace = true;
        }
        
        if (had_replace)
        {
            std::istringstream tmps(buffer);
            parseStream(tmps);
        }
        else
            std::cout << buffer << std::endl;
    } 
}

int main(int argc,  const char **argv)
{
    if (argc > 2)
    {
        const std::string tmp(argv[2]);
        if (tmp == "-h" || tmp == "--help")
        {
            usage();
            return 0;
        }            
    }
    parseStream(std::cin);
    return 0;
}