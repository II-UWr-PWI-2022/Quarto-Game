#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include "XML_scanner.hpp"
#include <string>
#include <vector>
#include <map>
#include <utility>

enum class Order
{
	ascending = 1,
	descending
};

enum class Sort_by
{
	nickname = 1,
	wins,
	draws,
	loses,
	points
};

class Player;

class DB_manager
{
	friend class Player;
	friend class XML_scanner;

private:
	// The path to the xml file with the database
	std::string db_access_path;
	// The map stores players sorted by nickname
	std::map<std::string, Player> users;

	// adds a player to the database
	void add_player(const Player &player);

	// updates the player's state in the database with the real state
	void update_player(const Player &player);

	XML_scanner scanner;

public:
	// The constructor takes the path to the xml file as an argument and loads the database from it
	DB_manager(const std::string access_path);

	// The destructor saves the database to an xml file
	~DB_manager();

	// Searches for a player in the database by given nickname. Returns Pair<True/False, Player>
	// Depending on the success of the search operation
	std::pair<bool, Player> search_nickname(std::string _nick_name);

	// It generates a ranking of players by sorting in terms of the indicated feature and in the designated order
	std::vector<Player> generate_ranking(Sort_by key, Order order_type);
};

#endif