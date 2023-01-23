#include <iostream>
#include <iomanip>
#include "db_manager.h"
#include "player.h"

using namespace std;

void test_start()
{
    DB_manager DB("db.xml");
    Player p1(DB);

    int task;
    string instructions;
    instructions += " __________________________________________________________________________________________\n";
    instructions += "| DB_MANAGER:                                                                              |\n";
    instructions += "| search_nickname(nickname) --> 0                 | generete_ranking(Sort_by, Order) --> 1 |\n";
    instructions += "| PLAYER:  ************************************   | log_out() --> 2                        |\n";
    instructions += "| log_in(nick, password) --> 3                    | is_logged() --> 4                      |\n";
    instructions += "| create_account(email, nick, password) --> 5     | delete_account(password) --> 6         |\n";
    instructions += "| change_nickname(new_nickname) --> 7             | change_password(new_password) --> 8    |\n";
    instructions += "| play_match(rival_type, status, bet_value) --> 9 | print_statistics() --> 10              |\n";
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
                p1.log_out();
                break;
            }

            case 3:
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

            case 4:
            {
                cout << "Is logged: " << boolalpha << p1.is_logged() << noboolalpha << "\n";
                break;
            }

            case 5:
            {
                cout << "Enter email, nickname and password\n";
                string email, nickname, password;
                cin >> email >> nickname >> password;
                
                if(p1.create_accout(email, nickname, password))
                    cout << "account created successfuly\n";
                else
                    cout << "account not created\n";
                break;
            }

            case 6:
            {
                cout << "Enter password to confirm operation\n";
                string password;
                cin >> password;

                if(p1.delete_account(password))
                    cout << "account deleted successfuly\n";
                else
                    cout << "account not deleted\n";

                break;
            }

            case 7:
            {
                cout << "Enter new_nickname\n";
                string nickname;
                cin >> nickname;

                if(p1.change_nickname(nickname))
                    cout << "nickname changed successfuly\n";
                else
                    cout << "nickname not changed\n";

                break;
            }



            case 8:
            {
                cout << "Enter new_password\n";
                string new_password;
                cin >> new_password;
                if(p1.change_password(new_password))
                    cout << "password changed successfuly\n";
                else
                    cout << "password not deleted\n";
                break;
            }

            case 9:
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

            case 10:
            {
                p1.print_statistics();
                break;
            }
        }
        cout << instructions;
    }
}
