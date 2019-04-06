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

Player::Player(){
    myName ="";
}

//adds a card to the hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

//makes a book or pair of cards if possible
//adds to the book vector for that player
void Player::bookCards(Card c1, Card c2){
    
    checkHandForBook(c1, c2);
    //add the cards to the myBooks vector
    myBook.push_back(c1);
    myBook.push_back(c2);

    //card is no longer in the hand, so remove them
    this->removeCardFromHand(c1);
    this->removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair. 
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2){

    //should be useful inside the book Cards function speed
    for( Card c : myHand){
        if(rankInHand(c)){ //if there is another card in the hand with that rank
            for(Card k: myHand){ //find that other card 
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
    //first check if the player has cards in their hands to give
    srand((unsigned)time(NULL));
    if(myHand.size() > 0){
        int i = rand() % myHand.size(); //pick a random card in the hand
        Card picked = myHand[i];
        return picked;
    } else
    {
        Card allout = Card(rand()%14,Card::spades); // picks a random card (suit doesnt matter)
    }
    
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    for (int i = 0; i < myHand.size(); i++){
        if (myHand[i].getRank() == c.getRank()){
            return true; //card is found return true
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    //marks the card to delete
    vector<Card>::iterator z;
    Card reserve = Card();
    bool found = false;
    for(z = myHand.begin(); z != myHand.end() && !found; z++){
        if((*z).getRank() == c.getRank()){
            found = true;
            reserve = (*z); 
        }
    }

    if(found){
        c = (*z);
        z = --z;
        //iterator operation to move the vector back one and remove the card
        myHand.erase(z);
    }
    return reserve; //returns the card it tried to delete
}

string Player::showHand() const{
    //Make a title to print before hand
    string pHand = myName;
    pHand.append(" hand -- ");

    //appends each hand to the end of the return string
    for(int i = 0; i < myHand.size(); i++){
        pHand.append(myHand[i].toString());
        pHand.append(" ");
    }
    return pHand;
}

//print through all books in book vector
string Player::showBooks() const{
    //Make a title to print before book
    string pBooks = myName;
    pBooks.append(" books -- ");

    //appends each book to the end of the return string
    for(int i = 0; i < myHand.size(); i++){
        pBooks.append(myHand[i].toString());
        pBooks.append(" ");
    }
    return pBooks;
}

//returns the number of cards in hand vector
int Player::getHandSize() const{
    return myHand.size();
}

//returns the number of books in book vector
int Player::getBookSize() const{
    return myHand.size() / 2;
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