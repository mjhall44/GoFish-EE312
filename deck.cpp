//Matthew Hall and Po-chih Chen
//deck cpp for go fish assignment
//Due: 4/12/19 Last edit: 4/4/19
//EE312

using namespace std;

#include "deck.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

void shuffleHelp(Card *c1, Card *c2); //takes two cards and changes their place in the array

Deck::Deck(){
    //creates a default deck of 52 cards, one of each type
    myCards[SIZE];
    myIndex = 0;
    for(int suits = 0; suits <=3; suits++){
        for(int ranks=1; ranks <=13; ranks++){
            myCards[myIndex]=Card(ranks, (Card::Suit)suits);
            myIndex++;
        }

    }
    myIndex = 0;
}

//to shuffle the deck, we used a shuffle helper function
void shuffleHelp(Card *c1, Card *c2){ //must use pointers to directly shuffle the deck
    //swaps the place of cards in the myCards deck vector
    Card temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
void Deck::shuffle()   // shuffle the deck, all 52 cards present
{
    //seed the random shuffle
    time_t seed = time(NULL);
    srand(seed);

    //starting with the first card, randomly swap through the array

    for(int i = SIZE-1; i >=0; i--){
        //cout << rand() << "   ::  i - "<<i << " :: ";
        
        int other = rand() % (i+1); //takes a number i to 0 and calls the shuffle help
        //i must have 1 added due to equalling 0 value giving a rand() return
        //cout <<"o - "<< other << endl;
        shuffleHelp(&myCards[i], &myCards[other]); //these elements are changed in the array
    }
}

Card Deck::dealCard()   // get a card, after 52 are dealt, fail 
{
    //index value is current place in array
    if(myIndex < SIZE){
        Card inPlay = myCards[myIndex];
        myIndex++;
        return inPlay; //the card is now in play        
    } else{
        cout << "Dealing Card fails, deck is full" << endl;

        Card def = Card(-1,Card:: spades); // suit doesn't matter
        return def; //returns a default card
    }

}

int  Deck::size() const
{
    //uses index value of where we are in the array
    return SIZE-myIndex; // my index starts at size 0 so initial is 52
}
// # cards left in the deck