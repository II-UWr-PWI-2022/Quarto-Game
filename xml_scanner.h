#ifndef XML_SCANNER
#define XML_SCANNER

#include <string>
#include <map>

class Player;

class XML_scanner{
public:
    void read_database(std::string access_path, std::map<std::string,Player> &users);
    void write_database(std::string access_path,const std::map<std::string, Player> &users);
};

#endif