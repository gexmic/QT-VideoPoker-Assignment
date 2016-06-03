#ifndef VIDEOPOKERGAME_H
#define VIDEOPOKERGAME_H

// /////////////////////////////////////////////////////////////////////
// File:  Jack or Bette Games
//
// Author: Michael Landry
// This assignment represents my own work and is in accordance with the College Academic Policy
//
// Copyright (c) 2016 All Right Reserved by Michael Landry
// Contributors:
// Description:  This is the game of poker Jack or Better, this programme simulate 5 card poker hand
// and the player is able to change any card for a redraw and have new card. the player win if I have a pair of jack or better
// all the card are old in the hand call like the real life.
//
// Date: juin 3 2016
// Revisions:
//
// ///////////////////////////////////////////////////////////////////

#include "deck.h"
#include "hand.h"


enum class CardColor {Black, Red};
enum class Rank{JACK_OR_BETTER, TWO_PAIR, THREE_OF_KIND, STRAIGHT, FLUSH, FULLHOUSE, FOUR_OF_KIND, STRAIGHT_FLUSH, ROYAL_FLUSH, NOTHING};

class videoPokerGame
{
public:
    videoPokerGame();

    bool isCardHoldAtIdx(int idx);
    void dealOrDraw();
    void toggelHoldAtIdx(int idx);
    std::string cardToStringAtIdx(int idx);
    CardColor cardColorAtIdx(int idx);
    bool isPlayedHand();
    bool isNewHand();
    void gameState(bool);
    Rank findValueOftheHand() const;

    void fillVectorWithTrue();
    void drawSecoundHand();


    static const std::map<Rank,std::string> _handRank;
    static const std::map<Rank, std::string> _handPay;

private:
    void drawCard();
    void dealCard();
    std::vector<bool> _hold;


Deck deck;
Hand hand;
bool _GameState;


};

#endif // VIDEOPOKERGAME_H
