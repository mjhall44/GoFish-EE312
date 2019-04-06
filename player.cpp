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
    myHand.push_back(c);
}

//makes a book or pair of cards if possible
//adds to the book vector for that player
void Player::bookCards(Card c1, Card c2){
    //checks hand for the max number of books possible
    for(int i=0; i <(myHand.size()%2); i++){
        if(checkHandForBook(c1, c2)){

        
        }

    }

}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){
    //should be useful inside the book Cards function speed
    for( Card c : myHand){
        if(rankInHand(c)){
            for(Card k: myHand){
                if(k.getRank() == c.getRank() && k!=c){
                    c1=c;
                    c2=k;
                    return true;
                }
            }
        }   
    }
    return false;
}

//OPTIONAL
// comment out if you decide to not use it    
//Does the player have a card with the same rank as c in her hand?
bool Player::rankInHand(Card c) const{
    //should be useful, quick scan through hand vector
    for(Card k : myHand){
        if(k.getRank() == c.getRank() && k!=c){
            return true;
        }
    }
    return false;
}

//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{

}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{

}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){

}

string Player::showHand() const{

}

//print through all books in book vector
string Player::showBooks() const{

}

//returns the number of cards in hand vector
int Player::getHandSize() const{

}

//returns the number of books in book vector
int Player::getBookSize() const{

}
    
//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2){
    //optional, return false
    return false;
}

//OPTIONAL
// comment out if you decide to not use it    
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c
bool Player::sameRankInHand(Card c) const{
    //optional, return false
    return false;
}