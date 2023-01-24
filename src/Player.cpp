#include "Player.h"
#include "DB_manager.h"
#include <algorithm>
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

Player::Player(DB_manager &db_manager) :
    password(""),
    connection_status(false),
    nickname(""),
    wins(0),
    draws(0),
    loses(0),
    points(0),
    DB(&db_manager){};

Player::Player() :
    password(""),
    connection_status(false),
    nickname(""),
    wins(0),
    draws(0),
    loses(0),
    points(0),
    DB(nullptr){};

bool Player::is_logged()
{
    return connection_status;
}


void Player::save_account()
{
    DB->update_player(*this); 
}


void Player::print_statistics()
{
    if(is_logged())
        cout << "Nickname: " << nickname << " Wins: " << wins << " Draws: " << draws << "  Loses: " << loses << " Points: " << points << "\n";
    else
        cout << "Ups. Player is not logged in\n";
}


bool Player::log_in(string nick, string _password)
{
    if(!log_out())
        return false;

    pair<bool, Player> check; 
    
    if(validate_nickname(nick))
        check = DB->search_nickname(nick);
    else
    {
        cerr << "Provided nickname is incorrect\n";
        return false;
    }

    if(check.first)
    {
        if(check.second.password == _password)
        {
            *this = check.second;
            connection_status = true;
            return true;
        }
        else
            cerr << "Invalid password\n";
    }
    else
        cerr << "Login is not in database\n";

    return false;
}

bool Player::log_out()
{
    if(DB == nullptr){
        cerr << "Player is not connected with DB_manager, operation unavailable\n";
        return false;
    }

    if(is_logged())
    {
        save_account();
        *this = Player(*this->DB);
    }

    return true;
}

bool Player::create_accout(string _nickname, string _password)
{
    if(!log_out())
        return false;
    
    if(validate_nickname(_nickname))
    {
        if(DB->search_nickname(_nickname).first)
        {
            cerr << "Nickname already taken, choose another one\n";
            return false;
        }
    }
    else
    {
        cerr << "Incorrect nickname format\n";
        return false;
    }

    if(!validate_password(_password))
    {
        cerr << "Incorrect pasword format\n";
        return false;
    }

    nickname = _nickname;
    password = _password;

    DB->add_player(*this);
    connection_status = true;
    return true;

}


void Player::play_match(Opponent rival_type, Game_status status, int bet_value)
{
    if(DB == nullptr){
        cerr << "Player is not connected with DB_manager, operation unavailable\n";
        return;
    }

    if(rival_type == Opponent::other_player)
    {
        if(status == Game_status::win)
        {
            ++wins;
            points += bet_value;
        }
        else if(status == Game_status::lose)
        {
            ++loses;
            points -= bet_value;
        }
    }
    else
    {
        int multi=0;
        if(rival_type == Opponent::bot_level_easy)
            multi = 1;
        else if(rival_type == Opponent::bot_level_medium)
            multi = 2;
        else
            multi = 3;


        if(status == Game_status::win)
        {
            ++wins;
            points += 5*multi;
        }
        else if(status == Game_status::draw)
        {
            ++draws;
            points += 2*multi;
        }
        else
        {
            ++loses;
            points -= multi;
        }   
    }


    if(is_logged())
    {
        if(points < 0) points = 0;
        save_account();
    }
}


#define NICKNAME_MIN_LENGTH 3
#define NICKNAME_MAX_LENGTH 20

bool Player::validate_nickname(string _nickname)
{
    if(_nickname.size() < NICKNAME_MIN_LENGTH || _nickname.size() > NICKNAME_MAX_LENGTH)
        return false;

    for(string::size_type i = 0; i < _nickname.size(); i++)
    {
        if(!isprint(_nickname[i]) || _nickname[i] == '@' || _nickname[i] == '<' || _nickname[i] == '>')
            return false;
    }

    return true;
}

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 60

bool Player::validate_password(string _password)
{
    if(_password.size() < PASSWORD_MIN_LENGTH || _password.size() > PASSWORD_MAX_LENGTH)
        return false;
    

    bool lower = false;
    bool upper = false;
    bool digit = false;

   for(string::size_type i = 0; i < _password.size(); i++)
   {
        if(isdigit(_password[i]))
            digit = true;
        else if(isalpha(_password[i]))
        {
            if(islower(_password[i]))
                lower = true;
            else
                upper = true;
        }
   }

    return (lower && upper && digit);

}

