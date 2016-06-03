#include "hand.h"

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

#include "Hand.h"

Hand::Hand()
{
}

Hand::~Hand()
{
}

// add card to different container vector, <map> of Face and int, <map> of Suit and int and a set of face.
void Hand::addCard(CardPtr p)
{
    _hand.push_back(p);
    _checkFace[p->face]++;
    _checkSuit[p->suit]++;
    _checkForStrait.insert(p->face);
}

// clear all the vector map and set.
void Hand::clear()
{
    _hand.clear();
    _checkFace.clear();
    _checkSuit.clear();
    _checkForStrait.clear();
}

// return the size of the vector _hand
int Hand::size()
{
    return static_cast<int>(_hand.size());
}

// bool to check if the hand is a pair
bool Hand::isPair() const
{
    auto itr = std::find_if(_checkFace.begin(), _checkFace.end(), [](std::pair<Face, int>e) {return e.second == 2; });

    if (itr != _checkFace.end())
    {
        return true;
    }
    else
        return false;
}

// bool to check if the hand is pair of Jack or Better
bool Hand::isJackOrBetter() const
{
    auto itr = std::find_if(_checkFace.begin(), _checkFace.end(), [](std::pair<Face, int>e) {return e.second == 2; });

    if (itr != _checkFace.end())
    {
        // this check for jack, queen, king, ace
        if (itr->first == Face::JACK || itr->first == Face::QUEEN || itr->first == Face::KING || itr->first == Face::ACE)
            return true;
        else
            return false;
    }
    return false;
}

// bool to check if the hand is 3 of a kind if it return 3 you have for of the same Face.
bool Hand::isThreeOfakind() const
{
    auto itr = std::find_if(_checkFace.begin(), _checkFace.end(), [](std::pair<Face, int>e) {return e.second == 3; });
    //count_if for two pair
    if (itr != _checkFace.end())
    {
        return true;
    }
    else
        return false;

}

// bool to check if the hand is 4 of a kind if it return 4 you have for of the same Face.
bool Hand::isFourOfaKind() const
{
    auto itr = std::find_if(_checkFace.begin(), _checkFace.end(), [](std::pair<Face, int>e) {return e.second == 4; });

    if (itr != _checkFace.end())
    {
        return true;
    }
    else
        return false;
}

// bool to check if the hand is full house by checking for 2 pair and 3 of a kind
bool Hand::isFullHouse() const
{
    if (isPair() == true && isThreeOfakind() == true)
    {
        return true;
    }
    else
        return false;
}

// bool to check if the hand is 2 pair
bool Hand::isTwoPair() const
{
    auto itr = std::count_if(_checkFace.begin(), _checkFace.end(), [](std::pair<Face, int>e) {return e.second == 2; });
    if (itr == 2)
    {
        return true;
    }
    return false;
}

// bool to check if the hand is flush by cheking int the map of Suit and if the number is 5 you have 5 different suit
bool Hand::isFlush() const
{
    auto itr = std::find_if(_checkSuit.begin(), _checkSuit.end(), [](std::pair<Suit, int>e) {return e.second == 5; });

    if (itr != _checkSuit.end())
    {
        return true;
    }
    return false;
}

// bool to check if the hand is a straight
bool Hand::isStrait() const
{
    // First I check if the size of the _hand is the same _checkForStrait
    if (_checkForStrait.size() == _hand.size())
    {
        int tmp = 0;
        int count = 0;
        int firstTurn = 0;
        int totalForHightStraight = 0;
        for (auto itr : _checkForStrait)
        {
            totalForHightStraight += static_cast<int>(itr);
            // the container is a set so everithing is in order
            // the first card I go to this if statement and check if is a As
            // if yes I add 13 to my variable totalForHightStraight.
            // I also have a count and it add up the value of each card in the set.
            // of the totalForHightStraight is 55 it a strait from 10 to as because by adding all the
            // value of the card that is the total for a strait from 10 to as.
            if (firstTurn == 0)
            {
                tmp = static_cast<int>(itr);
                count++;
                firstTurn++;
                if(itr == Face::ACE)
                    totalForHightStraight += 13;
            }

            if (tmp + count == static_cast<int>(itr))
            {
                count++;
            }
            if (count == 5)
            {
                return true;
            }
            if (totalForHightStraight == 55)
            {
                return true;
            }

        }
    }
    return false;
}

// bool to check if the hand is straitFlush by looking for a flush and a straight
bool Hand::isStraitFlush() const
{
    if (isFlush() == true && isStrait() == true)
    {
        return true;
    }
    return false;
}

// bool to check if the hand is a Royal Flush
bool Hand::isRoyalFlush() const
{
    // if isStraitFlush is true I look for a ACE and a KING to confirm the Royal Flush
    if (isStraitFlush() == true)
    {
        int kingAndAs = 0;
        for (auto itr : _checkForStrait)
        {
            if (itr == Face::ACE)
            {
                kingAndAs++;
            }

            if (itr == Face::KING)
            {
                kingAndAs++;
            }
            if (kingAndAs == 2)
            {
                return true;
            }

        }
    }
    return false;
}

int Hand::handSize()
{
    return static_cast<int>(_hand.size());
}

void Hand::fillVectorWithTrue()
{
    _hold.clear();
    for(int i = 0 ; i < _hand.size();++i)
    {
        _hold.push_back(false);
    }
}



 bool Hand::cardColor(int idx)
{
    if (_hand.at(idx)->suit == Suit::DIAMOND || _hand.at(idx)->suit == Suit::HEART)
        return true;
    else
        return false;
}

// convert the cardPrt to set a string to display to the user
std::string Hand::cardToString(int idx)
{
    std::string card=_hand.at(idx)->toString();
    return card;
}



// change from true to false in the vector for the card that the user whant to keep or not
void Hand::changCard(int cartToChange)
{

    _hold[cartToChange-1] = !_hold[cartToChange-1];

}

// assigne the value of a vector to the vector _hold in private in Hand class
void Hand::holdOrDraw(std::vector<bool> hold)
{
    _hold = hold;
}

// after the player decide with card he wan to draw I made a tmp vector of CardPtr and push back with card
// the player whant to keep and assigne the tmp vector to the _hand vector
void Hand::DrawCardForSecoundHand()
{
    std::vector<CardPtr> tmp;

    for (int i = 0; i < _hand.size(); ++i)
    {
        if (_hold.at(i))
        {
            tmp.push_back(_hand.at(i));
        }
    }
    // clear every container
    clear();
    _hand = tmp;

    // fill up the container with the new _hand vector with the card the player decite to keep
    for (auto itr : _hand)
    {
        _checkFace[itr->face]++;
        _checkSuit[itr->suit]++;
        _checkForStrait.insert(itr->face);
    }
}

bool Hand::isCardHoldAtIdx(int idx)
{
    if(_hold.at(idx))
        return true;
    else
        return false;
}

void Hand::toggelHoldAtIdx(int idx)
{
    _hold[idx] = !_hold[idx];
}



