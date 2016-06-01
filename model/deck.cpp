#include "deck.h"

///////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////

#include "Deck.h"
#include <time.h>


// the constructor create a deck of 52 different card
Deck::Deck()
{
    for (auto f : Card::faces)
        for (auto s : Card::suits)
            _deck.push_back(std::make_shared<Card>(Card(f,s)));
    _topOfDeck = _deck.size() - 1;

    // for test.

    /*_deck.push_back(std::make_shared<Card>(Face::QUEEN, Suit::HEART));
    _deck.push_back(std::make_shared<Card>(Face::FOUR, Suit::CLUB));
    _deck.push_back(std::make_shared<Card>(Face::EIGHT, Suit::DIAMOND));
    _deck.push_back(std::make_shared<Card>(Face::JACK, Suit::DIAMOND));
    _deck.push_back(std::make_shared<Card>(Face::THREE, Suit::HEART));*/

    srand(unsigned(time(0)));
}

Deck::~Deck()
{
}
// check if the deck is empty
bool Deck::isEmpty() const
{
    return (_topOfDeck < 0);
}

// shuffle de deck of card
void Deck::shuffle()
{
    for (int i = 0; i < _deck.size(); ++i)
    {
        swap(_deck[i], _deck[rand() % _deck.size()]);
    }
    _topOfDeck = _deck.size() - 1;
}

// draw one card from the deck
CardPtr Deck::draw()
{
    return _deck.at(_topOfDeck--);
}



