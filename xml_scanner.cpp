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
    {"</email>", 2},
    {"</password>", 3},
    {"</nickname>", 4},
    {"</wins>", 5},
    {"</draws>", 6},
    {"</loses>", 7},
    {"</points>", 8},
    {"</Quarto>", 9}
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
                                player.email = text;
                                break;
                            case 3:
                                player.password = text;
                                break;
                            case 4:
                                player.nickname = text;
                                break;
                            case 5:
                                player.wins = stoi(text);
                                break;
                            case 6:
                                player.draws = stoi(text);
                                break;
                            case 7:
                                player.loses = stoi(text);
                                break;
                            case 8:
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
