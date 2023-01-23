#include <iostream>
#include <iomanip>
#include "db_manager.h"
#include "player.h"

using namespace std;

// function checks the basic functionality provided by the classes: Player, DB_manager or XML_scanner
void test_start()
{
    DB_manager DB("db.xml");
    Player p1(DB);

    int task;
    string instructions;
    instructions += " __________________________________________________________________________________________\n";
    instructions += "| DB_MANAGER:                                                                              |\n";
    instructions += "| search_nickname(nickname) --> 0                 | generete_ranking(Sort_by, Order) --> 1 |\n";
    instructions += "| PLAYER:  ************************************   |                                        |\n";
    instructions += "| log_in(nick, password) --> 2                    | log_out() --> 3                        |\n";
    instructions += "| create_account(nick, password) --> 4            | is_logged() --> 5                      |\n";
    instructions += "| play_match(rival_type, status, bet_value) --> 6 | print_statistics() --> 7               |\n";
    instructions += " ===========================================================================================\n";

    cout << instructions;
    while(cin >> task)
    {

        switch(task)
        {
            case 0:
            {
                cout << "Enter nickname\n";
                string nickname;
                cin >> nickname;

                auto it = DB.search_nickname(nickname);
                if(it.first)
                {
                    cout<< it.second.nickname << " " << it.second.wins << " " << it.second.draws << " "
                        << it.second.loses << " " << it.second.points << "\n";
                }    
                else
                    cout << "Player with given nickname not found\n";

                break;
            }

            case 1:
            {
                cout<< "Enter 2 numbers\n" 
                    << "Sort by: nickname-->0, wins-->1, draws-->2 ,loses-->3, points-->4\n"
                    << "Order: ascending-->0, descending-->1\n";
                
                int a,b;
                cin >> a >> b;

                auto vec = DB.generate_ranking(static_cast<Sort_by>(a), static_cast<Order>(b));
                for(vector<Player>::size_type i = 1; i <= vec.size(); ++i)
                {
                    cout<< i << ". " << vec[i-1].nickname << " " << vec[i-1].wins << " " << vec[i-1].draws << " " << vec[i-1].loses 
                        << " " << vec[i-1].points << "\n";
                }

                break;
            }


            case 2:
            {
                cout << "Enter nickname and password\n";
                string nickname, password;
                cin >> nickname >> password;
                if(p1.log_in(nickname, password))
                    cout << "login successfuly\n";
                else
                    cout << "login failed\n";
                break;
            }
            
            case 3:
            {
                p1.log_out();
                break;
            }

            case 4:
            {
                cout << "Enter nickname and password\n";
                string nickname, password;
                cin >> nickname >> password;
                
                if(p1.create_accout(nickname, password))
                    cout << "account created successfuly\n";
                else
                    cout << "account not created\n";
                break;
            }

            case 5:
            {
                cout << "Is logged: " << boolalpha << p1.is_logged() << noboolalpha << "\n";
                break;
            }

            case 6:
            {
                
                cout << "Enter 2 numbers:\n";
                cout<< "Opponent : easy->1, medium->2, hard->3, Player->4\n"
                    << "Game_status: lose --> -1, draw --> 2, win --> 5\n";
                
                int a,b;
                cin >> a >> b;
                if(a == 4)
                {
                    cout << "Enter bet_value\n";
                    int c;
                    cin >> c;
                    p1.play_match(static_cast<Opponent>(a),static_cast<Game_status>(b),c);
                }
                else
                {
                    p1.play_match(static_cast<Opponent>(a),static_cast<Game_status>(b));
                }
                break;
            }

            case 7:
            {
                p1.print_statistics();
                break;
            }
        }
        cout << instructions;
    }
}
