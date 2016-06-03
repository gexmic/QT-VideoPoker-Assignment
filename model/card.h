#ifndef CARD_H
#define CARD_H

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

#pragma once

#include <string>
#include <set>
#include <map>
#include <iostream>

// enum class for Face and Suit
enum class Suit { CLUB, DIAMOND, HEART, SPADE };
enum class Face { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card
{
    Card(Face f, Suit s) : face(f), suit(s){}

    const Suit suit;
    const Face face;

    std::string toString() const;

    // class menbers
    static const std::set<Suit> suits;
    static const std::set<Face> faces;

    static const std::map<Face, std::string> faceNames;
    static const std::map<Suit, std::string> suitNames;
};

// operator overLoad
inline bool operator==(const Card& lhs, const Card& rhs) {
    return ((lhs.face == rhs.face)&&(lhs.suit == rhs.suit));
}

inline bool operator < (const Card& lhs, const Card& rhs) {
    if (lhs.face < rhs.face) return true;
    if ((lhs.face == rhs.face) && (lhs.suit < rhs.suit)) return true;
    return false;
}
inline bool operator!=(const Card& lhs, const Card& rhs) { return !operator==(lhs, rhs); }
inline bool operator>(const Card& lhs, const Card& rhs) { return operator<(rhs, lhs); }
inline bool operator <=(const Card& lhs, const Card& rhs) { return !operator>(lhs, rhs); }
inline bool operator >=(const Card& lhs, const Card& rhs) { return !operator<(lhs, rhs); }



std::ostream& operator<<(std::ostream& os, Card& c);

#endif // CARD_H
