#ifndef DECK_H
#define DECK_H


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
#include <vector>
#include <memory>
#include "Card.h"

struct Card;
using CardPtr = std::shared_ptr<Card>;

class Deck
{
public:
    Deck();
    ~Deck();
    bool isEmpty() const;
    CardPtr draw();
    void shuffle();

private:
    std::vector<CardPtr> _deck;
    int _topOfDeck;

};

#endif // DECK_H
