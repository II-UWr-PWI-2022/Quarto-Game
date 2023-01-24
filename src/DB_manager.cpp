#include "DB_manager.hpp"
#include "Player.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

DB_manager::DB_manager(const string access_path) : db_access_path(access_path)
{
	scanner.read_database(access_path, users);
}

DB_manager::~DB_manager()
{
	scanner.write_database(db_access_path, users);
}

pair<bool, Player> DB_manager::search_nickname(string nickname)
{
	auto it = users.find(nickname);
	if(it == users.end())
		return {false, Player()};

	return {true, it->second};
}

vector<Player> DB_manager::generate_ranking(Sort_by key, Order order_type)
{
	vector<Player> tmp;

	for(auto it : users)
	{
		tmp.push_back(it.second);
	}

	if(order_type == Order::ascending)
	{
		if(key == Sort_by::nickname)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.nickname < p2.nickname;} );
		}

		else if(key == Sort_by::points)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.points < p2.points;} );
		}

		else if(key == Sort_by::wins)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.wins < p2.wins;} );
		}

		else if(key == Sort_by::draws)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.draws < p2.draws;} );
		}

		else if(key == Sort_by::loses)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.loses < p2.loses;} );
		}
	}

	else
	{
		if(key == Sort_by::nickname)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.nickname > p2.nickname;} );
		}

		else if(key == Sort_by::points)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.points > p2.points;} );
		}

		else if(key == Sort_by::wins)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.wins > p2.wins;} );
		}

		else if(key == Sort_by::draws)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.draws > p2.draws;} );
		}

		else if(key == Sort_by::loses)
		{
			sort(tmp.begin(), tmp.end(), [](const Player &p1, const Player &p2) { return p1.loses > p2.loses;} );
		}
	}

	return tmp;
}


void DB_manager::add_player(const Player &player)
{
	users[player.nickname] = player;
}

void DB_manager::update_player(const Player &player)
{
	users[player.nickname] = player;
}