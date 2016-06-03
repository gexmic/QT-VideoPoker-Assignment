#include "card.h"

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

#include "Card.h"

// function to put the card to a string FaceName and SuitName
std::string Card::toString() const
{
    return faceNames.at(face) + suitNames.at(suit);
}




// initialize the different Suit
const std::set<Suit> Card::suits{
    Suit::CLUB,
    Suit::DIAMOND,
    Suit::HEART,
    Suit::SPADE };

// initialize the different Face
const std::set<Face> Card::faces{
    Face::ACE,
    Face::TWO,
    Face::THREE,
    Face::FOUR,
    Face::FIVE,
    Face::SIX,
    Face::SEVEN,
    Face::EIGHT,
    Face::NINE,
    Face::TEN,
    Face::JACK,
    Face::QUEEN,
    Face::KING };

// map to set the name of the Face
const std::map<Face, std::string> Card::faceNames{
{Face::ACE, "A"},
{Face::TWO, "2"},
{Face::THREE, "3"},
{Face::FOUR, "4"},
{Face::FIVE, "5"},
{Face::SIX, "6"},
{Face::SEVEN, "7"},
{Face::EIGHT, "8"},
{Face::NINE, "9"},
{Face::TEN,"10"},
{Face::JACK, "J"},
{Face::QUEEN, "Q"},
{Face::KING, "K"}
};

// map to set the name of the suit
const std::map<Suit, std::string> Card::suitNames{
    {Suit::HEART, "♥"},
    {Suit::DIAMOND, "♦"},
    {Suit::CLUB, "♣"},
    {Suit::SPADE, "♠"}
};

//operator overLoad for the cout
std::ostream & operator<<(std::ostream & os, Card & c)
{
    os << c.toString();
    return os;
    // TODO: insert return statement here
}
