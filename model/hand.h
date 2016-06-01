#ifndef HAND_H
#define HAND_H


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
//
// Date: mai 13 2016
// Revisions:
//
// ///////////////////////////////////////////////////////////////////

#pragma once
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Deck.h"
#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>

using CardPtr = std::shared_ptr<Card>;

class Hand
{
public:
    Hand();
    ~Hand();

    // initialize the function
    void addCard(CardPtr);
    void clear();
    void changCard(int);
    void holdOrDraw(std::vector<bool>);
    void DrawCardForSecoundHand();

    int size();

    bool isPair() const;
    bool isJackOrBetter() const;
    bool isThreeOfakind()const;
    bool isFourOfaKind()const;
    bool isFullHouse()const;
    bool isTwoPair()const;
    bool isFlush()const;
    bool isStrait()const;
    bool isStraitFlush() const;
    bool isRoyalFlush() const;

    std::string toString() const;
    std::string noHoldAndDrawToString()const;



private:
    // different container to hold data related to the card to check different poker hand
    std::vector<CardPtr> _hand;
    std::vector<bool> _hold;
    std::set<int> _cartToChange;
    std::map<Face, int> _checkFace;
    std::map<Suit, int> _checkSuit;
    std::set<Face> _checkForStrait;
};


#endif // HAND_H
