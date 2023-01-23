#ifndef PLAYER
#define PLAYER

#include <string>

enum class Opponent
{
    bot_level_easy = 1,
    bot_level_medium,
    bot_level_hard,
    other_player
};

enum class Game_status
{
    lose = -1,
    draw = 2,
    win = 5
};

class DB_manager;
class XML_scanner;

class Player
{
    friend class XML_scanner;
    friend class DB_manager;
private:
    std::string email;
    std::string password;
    bool connection_status;
public:
    std::string nickname;
    int wins;
    int draws;
    int loses;
    int points;
//***********************************************
    Player() = default;
    explicit Player(DB_manager &db_manager);

    bool log_in(std::string _nickname, std::string _password);
    bool log_out();
    bool is_logged();

    bool create_accout(std::string _email, std::string _nickname, std::string _password);
    bool delete_account(std::string _password);

    bool change_nickname(std::string new_nickname);
    bool change_password(std::string new_password);

    void play_match(Opponent rival_type, Game_status status, int bet_value = 0);
    void print_statistics();

private:
    bool validate_password(std::string _password);
    bool validate_nickname(std::string _nickname);
    bool validate_email(std::string &_email);

    void save_account();

    DB_manager *DB;
};

int max_bet_value(const Player &player1,const Player &player2);
bool check_bet_value(const Player &player1, const Player &player2, int bet_value);

#endif
