#include <iostream>
#include "card.cpp"
#include "card.h"

#include "deck.h"
#include "deck.cpp"

#include "player.h"
#include "player.cpp"

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
/*test.shuffle();
while(test.size() !=0){
    cout << "Card "<< idx <<": "<< test.dealCard() <<endl;
    idx++;
}
cout << "Empty deck error: " << test.dealCard() <<endl;
*/

//messing with player class
test = Deck();
test.shuffle();

Card drawn = test.dealCard();
Card drawn2 = test.dealCard();
cout << "cards drawn: " << drawn << "  " << drawn2 <<endl;
Player pz1 = Player("Kent");
Player pz2 = Player("Bent");
pz1.addCard(drawn);
pz2.addCard(drawn2);

cout << pz1.showHand() <<endl;

Card chosen = pz1.chooseCardFromHand();

cout << "Do you have a " << chosen.rankString(chosen.getRank()) << "?"<<endl;
pz1.addCard(Card(4,Card::spades));
pz1.addCard(Card(12,Card::spades));
pz2.addCard(Card(4,Card::spades));
pz2.addCard(Card(11,Card::spades));
if(pz2.cardInHand(chosen)){

    cout << "Here take it::: " << pz2.showHand() << endl;
    Card other = pz2.removeCardFromHand(chosen);
    cout << pz2.showHand() << endl;

    pz1.addCard(other);
    cout << pz1.showHand() << endl;

    cout << "new card " << other <<endl;
    pz1.bookCards(chosen, other);
    cout << "cards booked:: " << pz1.showHand() << endl;
    
} else
{

    cout << "Go fish nerd: ";
    pz1.addCard(test.dealCard());
    cout <<  pz1.showHand() << endl;
}



return 0;
}
