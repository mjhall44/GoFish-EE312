//Matthew Hall and Po-chih Chen
//card cpp for go fish assignment
//Due: 4/12/19 Last edit: 4/8/19
//EE312


#include <iostream>
#include <string>
using namespace std;

#include "card.cpp"



Card::Card(){         // default, ace of spades
    myRank = 1;
    mySuit = Suit::spades;    
}
Card(int rank, Suit s){
    myRank= rank;
    mySuit = Suit::s;
}

string Card::toString() const{
    string r; //corrects the value of rank to a string
    if(myRank==1){
        r="A";
    }else if(myRank==11){
        r="J";
    }else if(myRank==12){
        r="Q";
    }else if(myRank==13){
        r="K";
    }else{
     r= <string>myRank;
    }
    string s;//corrects the value of suit to a string
    if(mySuit ==0){
        s='s';
    } else if(mySuit==1){
        s='h';
    } else if(mySuit==1){
        s='d';
    } else if(mySuit==1){
        s='c';
    }
    return (r+s);//appends together to output
}  // return string version e.g. Ac 4h Js
bool Card::sameSuitAs(const Card& c) const  // true if suit same as c
{
    return (this->mySuit == c->mySuit);
}
// return rank, 1..13
int  Card::getRank() const
{
    return myRank;
}
// return "s", "h",...
string suitString(Suit s) const {
      string s;//corrects the value of suit to a string
    if(mySuit ==0){
        s='s';
    } else if(mySuit==1){
        s='h';
    } else if(mySuit==1){
        s='d';
    } else if(mySuit==1){
        s='c';
    }  
    return s;
} 

string rankString(int r) const
{// return "A", "2", ..."Q"  
    string r; //corrects the value of rank to a string
    if(myRank==1){
        r="A";
    }else if(myRank==11){
        r="J";
    }else if(myRank==12){
        r="Q";
    }else if(myRank==13){
        r="K";
    }else{
     r= <string>myRank;
    }
    return r;
}
bool operator == (const Card& rhs) const{
    if(myRank == rhs.myRank){
        if(mySuit == rhs.mySuit){
            return true;
        }
    }
    return false;
}
bool operator != (const Card& rhs) const{
    if(myRank == rhs.myRank){
        if(mySuit == rhs.mySuit){
            return false;
        }
    }
    return true;
}