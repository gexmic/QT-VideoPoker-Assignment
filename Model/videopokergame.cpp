#include "videopokergame.h"

videoPokerGame::videoPokerGame()
{
    std::vector<bool> _hold(5, true);
    _GameState=true;
}

bool videoPokerGame::isCardHoldAtIdx(int idx)
{
    if(_hold.at(idx))
        return true;
    else
        return false;
}

std::string videoPokerGame::cardToStringAtIdx(int idx)
{
    return hand._hand.at(idx)->toString();
}

CardColor videoPokerGame::cardColorAtIdx(int idx)
{
    if (hand._hand.at(idx)->suit == Suit::DIAMOND || hand._hand.at(idx)->suit == Suit::HEART)
        return CardColor::Red;
    else
        return CardColor::Black;
}

bool videoPokerGame::isPlayedHand()
{
    if(_GameState)
        return true;
    else
        return false;
}

bool videoPokerGame::isNewHand()
{
    if(_GameState == false)
        return true;
    else
        return false;
}

void videoPokerGame::toggelHoldAtIdx(int idx)
{
    _hold[idx-1] = !_hold[idx-1];
}

void videoPokerGame::dealOrDraw()
{
    if(_GameState)
    {
        while (hand._hand.size() < 5)
            {
                hand.addCard(deck.draw());
            }

    }
    else
    {
        hand._hand.clear();
        deck.shuffle();
        while (hand._hand.size() < 5)
            {
                hand.addCard(deck.draw());
            }
    }
}
