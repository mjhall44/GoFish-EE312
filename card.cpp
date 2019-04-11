//Matthew Hall and Po-chih Chen
//card cpp for go fish assignment
//Due: 4/12/19 Last edit: 4/8/19
//EE312

using namespace std;

#include "card.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sstream>



//default card classes Card() 
//Card(int rank, Suit s) where the suit is considered and rank is pre set
Card::Card(){         // default, ace of spades
    myRank = 1;
    mySuit = spades;    
}

Card::Card(int rank, Suit s){
    myRank= rank;
    mySuit = s;
}

string Card::toString() const{
    string r = this->rankString(myRank); //corrects the value of rank to a string
    string s = this->suitString(mySuit);
    return (r+s);//appends together to output
}  // return string version e.g. Ac 4h Js

bool Card::sameSuitAs(const Card& c) const  // true if suit same as c
{
    return (this->mySuit == c.mySuit);
}
// return rank, 1..13
int  Card::getRank() const
{
    return myRank;
}
// return "s", "h",...
string Card::suitString(Suit s) const 
{
    //corrects the value of suit to a string
    switch(s){
        case spades : return "s";
        case hearts : return "h";
        case diamonds : return "d";
        case clubs : return "c";

    }
} 

string Card::rankString(int r) const
{// return "A", "2", ..."Q"

    string z; //corrects the value of rank to a string
    stringstream ss;
    if(r==1){
        z="A";
    }else if(r==11){
        z="J";
    }else if(r==12){
        z="Q";
    }else if(r==13){
        z="K";
    }else{
     ss<<r;
     z= ss.str();
    }
    return z;
}
bool Card::operator == (const Card& rhs) const{
    if(myRank == rhs.myRank){
        if(mySuit == rhs.mySuit){
            return true;
        }
    }
    return false;
}
bool Card::operator != (const Card& rhs) const{
    if(myRank == rhs.myRank){
        if(mySuit == rhs.mySuit){
            return false;
        }
    }
    return true;
}

ostream& operator << (ostream& out, const Card& c){

    out << c.toString();
    return out;
}

Card::~Card(){}
