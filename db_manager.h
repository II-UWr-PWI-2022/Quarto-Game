#ifndef DB_MANAGER
#define DB_MANAGER

#include "xml_scanner.h"
#include <string>
#include <vector>
#include <map>
#include <utility>

enum class Order{
    ascending = 0,
    descending
};

enum class Sort_by{
    nickname = 0,
    wins,
    draws,
    loses,
    points
};

class Player;

class DB_manager{
    friend class Player;
    friend class XML_scanner;
private:
    std::string db_access_path;
    std::map<std::string, Player> users;

public:
    DB_manager(std::string access_path);
    ~DB_manager();
    std::pair<bool, Player> search_nickname(std::string _nick_name);
    std::vector<Player> generate_ranking(Sort_by key, Order order_type);

private:

    void add_player(const Player &player);
    void remove_player(const Player &player);
    void update_player(const Player &player);
    
    XML_scanner scanner;
};

#endif