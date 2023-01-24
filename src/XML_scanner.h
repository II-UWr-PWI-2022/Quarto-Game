#ifndef XML_SCANNER
#define XML_SCANNER

#include <string>
#include <map>

class Player;

class XML_scanner
{
public:
    // function that reads data from an xml file and saves it to the map<string, Player>
    void read_database(std::string access_path, std::map<std::string,Player> &users);
    // the function overwrites the xml file with data from the map
    void write_database(std::string access_path,const std::map<std::string, Player> &users);
};

#endif