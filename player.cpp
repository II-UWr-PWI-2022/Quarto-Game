#include "player.h"
#include "db_manager.h"
#include <algorithm>
#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

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

