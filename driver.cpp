#include <iostream>
#include "card.cpp"
#include "card.h"

#include "deck.h"
#include "deck.cpp"

int main() {

//messing with the card class

Card c = Card();
cout << c << endl;

Card g= Card(3, (Card::Suit)2);
Card f= Card(12, (Card::Suit)3);
cout << "Card g: " << g << endl;
cout << "Card f: " << f << endl;

cout << "Are they the same: "<< g.sameSuitAs(f) << endl;

//messing with the deck class
cout << "A new deck- shuffled" << endl;
Deck test = Deck();
int idx =0;
test.shuffle();
while(test.size() !=0){
    cout << "Card "<< idx <<": "<< test.dealCard() <<endl;
    idx++;
}
cout << "Empty deck error: " << test.dealCard() <<endl;



return 0;
}
