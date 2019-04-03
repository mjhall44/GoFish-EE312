//Matthew Hall and Po-chih Chen
//player cpp for go fish assignment
//Due: 4/12/19 Last edit: 4/4/19
//EE312

using namespace std;

#include "player.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>


//adds a card to the hand
void Player::addCard(Card c){

}

//makes a book or pair of cards if possible
void Player::bookCards(Card c1, Card c2){

}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool PlayercheckHandForBook(Card &c1, Card &c2);

//OPTIONAL
// comment out if you decide to not use it    
//Does the player have a card with the same rank as c in her hand?
bool rankInHand(Card c) const; 

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card chooseCardFromHand() const; 

//Does the player have the card c in her hand?
bool cardInHand(Card c) const; 

//Remove the card c from the hand and return it to the caller
Card removeCardFromHand(Card c); 

string showHand() const; 
string showBooks() const; 

int getHandSize() const; 
int getBookSize() const; 
    
//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool checkHandForPair(Card &c1, Card &c2);

//OPTIONAL
// comment out if you decide to not use it    
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c
bool sameRankInHand(Card c) const; 