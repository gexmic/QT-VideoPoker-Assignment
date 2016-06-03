#ifndef VIDEOPOKERGAME_H
#define VIDEOPOKERGAME_H

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
