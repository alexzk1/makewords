#include <string>
#include <locale>         // std::locale, std::tolower
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/locid.h>

//I think, those characters should not be part of "word" as well. 
const static std::string delimeters="~`!@#$%^&*()-=+><,.?/|\\\"';:][{}_";


class InputParser
{
    public:
        InputParser (const int argc, const char **argv): tokens(argc)
        {            
            for (int i=1; i < argc; ++i)
                tokens.push_back(std::string(argv[i]));
        }                
        bool cmdOptionExists(const std::string &option) const
        {
            return std::find(tokens.cbegin(), tokens.cend(), option) != tokens.end();
        }
        bool cmdOptionOneExists(const std::vector<std::string>& options) const
        {
             for (const std::string& o : options)
                   if (cmdOptionExists(o))
                      return true;
             return false;
        }
    private:
        std::vector <std::string> tokens;
};


static void usage()
{
    std::cout << "Program breaks STDIN into words and prints it in STDOUT each word on new line." << std::endl;
    std::cout << "\t-h, --help  - prints this message." << std::endl;
    std::cout << "\t-l, --lower - does conversition to lowercase as well (expecting UTF-8 on input and doing same on output)." << std::endl;        
}

static void parseStream(std::istream& in, const bool lower)
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
            parseStream(tmps, lower);
        }
        else
        {
            if (lower)
            {
                icu::UnicodeString someUString(buffer.c_str(), "UTF-8");
                std::cout << someUString.toLower("UTF-8") << std::endl;
            }
            else
                std::cout << buffer << std::endl;
        }
    } 
}

int main(int argc,  const char **argv)
{
    const static InputParser input(argc, argv);
    bool lower = false;
    
    if (input.cmdOptionOneExists({"-h", "--help"}))    
    {
        usage();
        return 0;
    }   
    
    lower = input.cmdOptionOneExists({"-l", "--lower"});
    
    parseStream(std::cin, lower);
    return 0;
}