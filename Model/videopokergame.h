#ifndef VIDEOPOKERGAME_H
#define VIDEOPOKERGAME_H

#include "deck.h"
#include "hand.h"


class videoPokerGame
{
public:
    videoPokerGame();

    void isCardHoldAtIdx(int idx);
    void dealOrDraw();
    void toggelHoldAtIdx(int idx);
    void cardToStringAtIdx(int idx);
    void cardColorStringAtIdx(int idx);
    bool isPlayedHand();
    bool isNewHand();



private:
    void drawCard();
    void dealCard();
    std::vector<bool> _hold;

Deck deck;
Hand hand;
bool _GameState;


};

#endif // VIDEOPOKERGAME_H
