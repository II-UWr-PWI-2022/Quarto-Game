#include "player.h"
#include "db_manager.h"
#include <algorithm>
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

Player::Player(DB_manager &db_manager) :
    email(""),
    password(""),
    connection_status(false),
    nickname(""),
    wins(0),
    draws(0),
    loses(0),
    points(0),
    DB(&db_manager){};


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
        cout << email << " "<< nickname << " " << password << " " << wins << " " << draws << " " << loses << " " << points << "\n";
    else
        cout << nickname << " " << wins << " " << draws << " " << loses << " " << points << "\n";
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

bool Player::create_accout(string _email ,string _nickname, string _password)
{
    if(!log_out())
        return false;

    if(!validate_email(_email))
    {
        cerr << "Incorrect email format\n";
        return false;
    }
    
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

    email = _email;
    password = _password;
    nickname = _nickname;

    DB->add_player(*this);
    connection_status = true;
    return true;

}

bool Player::delete_account(string _password)
{
    if(DB == nullptr){
        cerr << "Player is not connected with DB_manager, operation unavailable\n";
        return false;
    }

    if(is_logged())
    {
        if(password == _password)
        {
            DB->remove_player(*this);
            log_out();
            return true;
        }
        else
            cerr << "Password doesnt match. Try again\n";
    }
    else
        cerr << "Player is not logged in\n";

    return false;
}


bool Player::change_password(string new_password)
{
    if(DB == nullptr){
        cerr << "Player is not connected with DB_manager, operation unavailable\n";
        return false;
    }

    if(is_logged())
    {
        if(!validate_password(new_password))
        {
            cerr << "Incorrect pasword format\n";
            return false;
        }
        
        password = new_password;
        save_account();
        return true;
    }
    else
        cerr << "Player is not logged in\n";
    
    return false;
}

bool Player::change_nickname(string new_nickname)
{
    if(DB == nullptr){
        cerr << "Player is not connected with DB_manager, operation unavailable\n";
        return false;
    }

    if(is_logged())
    {
        if(!validate_nickname(new_nickname))
        {
            cerr << "Incorrect nickname format\n";
            return false;
        }

        if(DB->search_nickname(new_nickname).first == true)
        {
            cerr << "The given nickname is already taken\n";
            return false;
        }
        
        DB->remove_player(*this);
        nickname = new_nickname;
        save_account();
        return true;
    }
    else
        cerr << "Player is not logged in\n";
    
    return false;
}


void Player::play_match(Opponent rival_type, Game_status status, int bet_value)
{
    if(DB == nullptr){
        cerr << "Player is not connected with DB_manager, operation unavailable\n";
        return;
    }

    if(is_logged())
    {
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

        if(points < 0) points = 0;

        save_account();
    }
    else
        cerr << "Player is not logged in\n";
}




#define NICKNAME_MIN_LENGTH 3
#define NICKNAME_MAX_LENGTH 20

bool Player::validate_nickname(string _nickname)
{
    if(_nickname.size() < NICKNAME_MIN_LENGTH || _nickname.size() > NICKNAME_MAX_LENGTH)
        return false;

    for(string::size_type i = 0; i < _nickname.size(); ++i)
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

   for(string::size_type i = 0; i < _password.size(); ++i)
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


#define EMAIL_MIN_LENGTH 8
#define EMAIL_MAX_LENGTH 60

bool Player::validate_email(string &_email)
{
    if(_email.size() < EMAIL_MIN_LENGTH || _email.size() > EMAIL_MAX_LENGTH)
        return false;

    int at_counter = 0;

    int names_in_user = 0, names_in_domain = 0;

    if( !isalnum(_email[0]) || !isalnum(_email[_email.size() -1]))
        return false;

    for(string::size_type i = 1; i < _email.size()-1; ++i)
    {
        if(_email[i] == '@')
        {
            if( !isalnum(_email[i-1]) || !isalnum(_email[i+1]))
                return false;

            ++at_counter;
        }
        else if(_email[i] == '.')
        {
            if(_email[i+1] == '.' || _email[i+1] == '-')
                return false;

            if(at_counter < 1)
                ++names_in_user;
            else
                ++names_in_domain;
        }
        else if(_email[i] == '-')
        {
            if(_email[i+1] == '-' || _email[i+1] == '.')
                return false;
        }
        else if( !isalnum(_email[i]))
        {
            return false;
        }
        else if(isalpha(_email[i]))
        {
            _email[i] = tolower(_email[i]);
        }         
    }

        ++names_in_user, ++names_in_domain;

        if(names_in_user < 1 || names_in_domain < 2)
            return false;

    return true;
}



int max_bet_value(const Player &player1,const Player &player2)
{
    return min(player1.points, player2.points);
}

bool check_bet_value(const Player &player1, const Player &player2, int bet_value)
{
    return (player1.points <= bet_value && player2.points <= bet_value);
}

