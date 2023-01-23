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
    
    // The function accepts nick and password as arguments, if logging in successfully returns true, otherwise false
    bool log_in(std::string _nickname, std::string _password);
    // Saves the player's data to the database and logs him out
    bool log_out();
    // The function returns the player's current login status
    bool is_logged();

    // Creates a new player account - email may already exist in the database, but the nickname must be unique
    bool create_accout(std::string _nickname, std::string _password);

    void play_match(Opponent rival_type, Game_status status, int bet_value = 0);
    
    // Prints all data of the current player
    void print_statistics();

private:
    // Checks whether the given password is in the correct form:    length (8 - 60) 
    // It should consist of at least one uppercase letter, lowercase letter, number and any other characters    
    bool validate_password(std::string _password);

    // Checks whether the given nickname is in the correct form:    length (3 - 20)
    // It cannot consist of non-printable characters and @, <, > other characters are allowed 
    bool validate_nickname(std::string _nickname);

    // Saves the current state of the player's account to the database
    void save_account();

    DB_manager *DB;
};

int max_bet_value(const Player &player1,const Player &player2);
bool check_bet_value(const Player &player1, const Player &player2, int bet_value);

#endif
