#include "xml_scanner.h"
#include "player.h"

#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

static const string prolog = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

static const map<string, int> element  = {
    {"</player>", 1},
    {"</nickname>", 2},
    {"</password>", 3},
    {"</wins>", 4},
    {"</draws>", 5},
    {"</loses>", 6},
    {"</points>", 7},
    {"</Quarto>", 8}
};

void XML_scanner::read_database(string access_path, map<string, Player> &users)
{
    ifstream file(access_path, ios::in);
    
    if(file.is_open())
    {
        string line;
        getline(file, line);

        Player player;
        
        while(getline(file, line))
        {
            string command;
            string text;

            for(string::size_type i = 0; i < line.size(); ++i)
            {
                if(isspace(line[i]))
                    continue;

                if(line[i] == '<')
                {
                    while(line[i] != '>')
                    {
                        command += line[i];
                        ++i;
                    }
                    command += line[i];

                    auto it = element.find(command);
    
                    if(it != element.end())
                    {
                        switch(it->second)
                        {
                            case 1:
                                users[player.nickname] = player;
                                break;
                            case 2:
                               player.nickname = text;
                                break;
                            case 3:
                                player.password = text;
                                break;
                            case 4:
                                player.wins = stoi(text);
                                break;
                            case 5:
                                player.draws = stoi(text);
                                break;
                            case 6:
                                player.loses = stoi(text);
                                break;
                            case 7:
                                player.points = stoi(text);
                                break;
                        }
                    }
                    else
                    {
                        command.clear();
                        text.clear();
                    }
                    continue;
                }

                text += line[i];
            }

        }

        file.close();
    }
    else cerr << "Unable to open database\n";
}


void XML_scanner::write_database(std::string access_path,const map<string, Player> &users)
{
    ofstream file(access_path, ios::out | ios::trunc);

    if(file.is_open())
    {
        int index = 1;
        file << prolog;
        file << "\n<Quarto users=\"" << users.size() << "\">\n";
        for(auto it : users)
        {
            file<< "    <player id=\""  << index            << "\">\n"
                << "        <nickname>" << it.second.nickname  << "</nickname>\n"
                << "        <password>" << it.second.password  << "</password>\n"
                << "        <wins>"     << it.second.wins      << "</wins>\n"
                << "        <draws>"    << it.second.draws     << "</draws>\n"
                << "        <loses>"    << it.second.loses     << "</loses>\n"
                << "        <points>"   << it.second.points    << "</points>\n"
                << "    </player>\n";
            ++index;
        }
        file << "</Quarto>\n";

        file.close();
    }
    else cerr << "Unable to open database\n";
}
