#pragma once
#include"Person.h"

/*
* Function that checks whether a given string has numbers in it
* @param input text
* @bool if text has number in it
*/
bool checkString(string text);

/*
* Function that checks the age of a registered user
* @param birth day of the users
* @param  birth month
* @param birth year
* @return bool if user is adult
*/
bool checkIfAdult(int day, int month, int year); 

/*
* Function that checks if the given card number is correct
* @param cards number
* @return bool if number is correct
*/
bool checkCardNumber(string card_nb_); 

/*
* Function that checks the strength of the user's password
* @param users password
* @return bool is password is strong enough
*/
bool checkPassword(string password);
 
 


