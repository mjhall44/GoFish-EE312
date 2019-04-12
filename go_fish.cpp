//Matthew Hall and Po-chih Chen
//go_fish cpp for go fish assignment
//Due: 4/12/19 Last edit: 4/09/19
//EE312

#include <iostream>    // Providesmyfile  and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <vector>
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( ) {
    ofstream myfile; // declare an output file stream object
    myfile.open("gofish_results.txt"); // open a text file and associate it with the stream object

    Deck d = Deck();  //create pristine deck
    /*for (int i=0; i<52; i++){   // show pristine deck
        cout<<d.myCards[i]<<" "<<endl;
    }*/
    d.shuffle(); // random sorting

    //DEALING 7 CARDS TO BOTH PLAYERS AND CHECK FOR BOOKS
    int numCards = 7; // two players
    Player p1("Matt");
    Player p2("PoChih");
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    myfile << p1.showHand() << endl; // show players' initial hands
    myfile << p2.showHand() << endl;

    Card c1 = Card();                // initialization
    Card c2 = Card();
    while (p1.checkHandForBook(c1, c2)) { //make pairs if possible for both players
        p1.bookCards(c1, c2);
    }
    while (p2.checkHandForBook(c1, c2)) {
        p2.bookCards(c1, c2);
    }

    myfile << p1.showHand() << endl; // show players' hands after initial booking-check
    myfile << p2.showHand() << endl;

    myfile << "--------START GAME-------" << endl;

    while (((p1.getBookSize() <= 13) && (p2.getBookSize() <= 13)) && !((p1.getBookSize() + p2.getBookSize()) ==
                                                                       26)) {  //game ends when one player has more than 13 books or all 26 books formed

        //***********MATT'S TURN

        Card card1;
        Card picked1;    // initialization
        if (p1.getHandSize() > 0) {
            card1 = p1.chooseCardFromHand(); //p1 chooses a card from hand and asks p2 if they have the card(s)
            myfile << p1.getName() << " asks- Do you have a " << card1.rankString(card1.getRank()) << "?" << endl;
            //p2 checks his hand for requested card
            if (!(p2.cardInHand(card1))) {//if the player doesn't have the requested card, print go fish
                myfile << p2.getName() << " says: Go Fish" << endl;
                // check empty deck???
                if (d.size() > 0) {
                    Card picked;
                    picked = d.dealCard();
                    p1.addCard(picked);
                    myfile << p1.getName() << " draws " << picked.toString() << endl;
                    if (p1.checkHandForBook(c1, c2)) {
                        p1.bookCards(c1, c2);
                    }
                } else if (d.size() == 0) {
                    myfile << " There is no more card in the deck to be drawn" << endl;
                }
            } else {// if yes, remove the card of the same rank from p2's hand and add to p1's hand
                while (p2.cardInHand(card1)) {
                    myfile << p2.getName() << " has " << card1.rankString(card1.getRank()) << endl;
                    p1.addCard(p2.removeCardFromHand(card1));
                    //check for books
                    if (p1.checkHandForBook(c1, c2)) {
                        p1.bookCards(c1, c2);
                    }
                }
            }
            myfile << p1.showHand() << endl; // show players' hands
            myfile << p2.showHand() << endl;
            myfile << p1.showBooks() << endl; // show players' current book
            myfile << p2.showBooks() << endl;
            myfile << p1.getName() << "'s book size is: " << p1.getBookSize() << endl;
            myfile << p2.getName() << "'s book size is: " << p2.getBookSize() << endl << endl;
        } else {
            if (d.size() > 0) { // no card in hand -- draw if deck is not empty
                picked1 = d.dealCard();
                p1.addCard(picked1);
                //if (p1.checkHandForBook(c1, c2)) {
                //p1.bookCards(c1, c2);
                //}
            }
            // check for no deck no hand??
            myfile << p1.getName() << " has empty hand so draws " << picked1.toString() << endl;
            myfile << p1.showHand() << endl; // update player's after picking up a card if the player doesn't ask
            myfile << p2.showHand() << endl;
        }

        //**************POCHIH'S TURN

        Card card2;
        Card picked2;  // initialization
        //int oldBookSize;
        if (p2.getHandSize() > 0) {
            card2 = p2.chooseCardFromHand();
            myfile << p2.getName() << " asks: Do you have a " << card2.rankString(card2.getRank()) << "?" << endl;
            // p1 checks his hand for requested card
            if (!(p1.cardInHand(card2))) {//if the player doesn't have the requested card, print go fish
                myfile << p1.getName() << " says: Go Fish" << endl;
                // check empty deck???
                if (d.size() > 0) {
                    Card picked3;
                    picked3 = d.dealCard();
                    p2.addCard(picked3);
                    myfile << p2.getName() << " draws " << picked3.toString() << endl;
                    if (p2.checkHandForBook(c1, c2)) {
                        p2.bookCards(c1, c2);
                    }
                } else if (d.size() == 0) {
                    myfile << " There is no more card in the deck to be drawn" << endl;
                }
            } else {// while true, remove the card of the same rank from p1's hand and add to p2's hand
                while (p1.cardInHand(card2)) {
                    myfile << p1.getName() << " has " << card2.rankString(card2.getRank()) << endl;
                    p2.addCard(p1.removeCardFromHand(card2));
                    //check for books
                    if (p2.checkHandForBook(c1, c2)) {
                        p2.bookCards(c1, c2);
                        //oldBookSize =p2.getBookSize();
                    }
                }
            }
            myfile << p1.showHand() << endl; // show players' hands
            myfile << p2.showHand() << endl;
            myfile << p1.showBooks() << endl; // show players' current book
            myfile << p2.showBooks() << endl;
            myfile << p1.getName() << "'s book size is: " << p1.getBookSize() << endl;
            myfile << p2.getName() << "'s book size is: " << p2.getBookSize() << endl << endl;
        } else {
            if (d.size() > 0) { // no card in hand -- draw if deck is not empty
                Card picked2;
                picked2 = d.dealCard();
                p2.addCard(picked2);
                //if (p2.checkHandForBook(c1, c2)) {
                //p2.bookCards(c1, c2);
                //}
            }
            myfile << p2.getName() << " has empty hand so draws " << picked2.toString() << endl;
            myfile << p1.showHand() << endl; // update player's after picking up a card if the player doesn't ask
            myfile << p2.showHand() << endl;
        }
    }

    if (p1.getBookSize() == p2.getBookSize()) {
        myfile << p1.getName() << " and " << p2.getName() << " are tied!" << endl;
    } else if (p1.getBookSize() > p2.getBookSize()) {
        myfile << p1.getName() << " Crushed " << p2.getName() << "!" << endl;
    } else {
        myfile << p2.getName() << " Crushed " << p1.getName() << "!" << endl;
    }

    myfile << "GAME OVER." << endl;
    myfile.close(); // close the file
    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
