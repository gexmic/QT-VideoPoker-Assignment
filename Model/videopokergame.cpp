#include "videopokergame.h"

videoPokerGame::videoPokerGame()
{
    _GameState=true;
    deck.shuffle();
}
// fill up the map of the hand rank whit the Rank and a string to tell the user what he got
const std::map<Rank, std::string> videoPokerGame::_handRank{
    {Rank::JACK_OR_BETTER, "You have one pair of jack or better"},
    {Rank::TWO_PAIR, "You have two pair"},
    {Rank::THREE_OF_KIND,"You have three of a kind"},
    {Rank::STRAIGHT,"You have Straight"},
    {Rank::FLUSH,"You have a Flush"},
    {Rank::FULLHOUSE,"You have a Full House"},
    {Rank::FOUR_OF_KIND,"You have a Four Of A Kind"},
    {Rank::STRAIGHT_FLUSH,"You have a Straight Flush"},
    {Rank::ROYAL_FLUSH,"You have a Royal Flush"},
    {Rank::NOTHING, "Nothing"}
};

// fill up the map whit the Rank and the value of how much time your bett pay depend from the Rank
const std::map<Rank, std::string> videoPokerGame::_handPay{
    {Rank::NOTHING, "0"},
    {Rank::JACK_OR_BETTER, "1" },
    {Rank::TWO_PAIR, "2" },
    {Rank::THREE_OF_KIND,"3" },
    {Rank::STRAIGHT,"4" },
    {Rank::FLUSH,"6" },
    {Rank::FULLHOUSE,"9" },
    {Rank::FOUR_OF_KIND, "25"},
    {Rank::STRAIGHT_FLUSH,"50" },
    {Rank::ROYAL_FLUSH,"250" }
};

bool videoPokerGame::isCardHoldAtIdx(int idx)
{
    return hand.isCardHoldAtIdx(idx);
}

std::string videoPokerGame::cardToStringAtIdx(int idx)
{
    return hand.cardToString(idx);
}

CardColor videoPokerGame::cardColorAtIdx(int idx)
{
    if (hand.cardColor(idx))
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

void videoPokerGame::gameState(bool b)
{
    _GameState = b;
}

Rank videoPokerGame::findValueOftheHand() const
{
    if (hand.isRoyalFlush()) return Rank::ROYAL_FLUSH;
    else if (hand.isStraitFlush()) return Rank::STRAIGHT_FLUSH;
    else if (hand.isFourOfaKind()) return Rank::FOUR_OF_KIND;
    else if (hand.isFullHouse())return Rank::FULLHOUSE;
    else if (hand.isFlush())return Rank::FLUSH;
    else if (hand.isStrait()) return Rank::STRAIGHT;
    else if (hand.isThreeOfakind())return Rank::THREE_OF_KIND;
    else if (hand.isTwoPair()) return Rank::TWO_PAIR;
    else if (hand.isJackOrBetter())return Rank::JACK_OR_BETTER;
    else return Rank::NOTHING;

}

void videoPokerGame::fillVectorWithTrue()
{
    hand.fillVectorWithTrue();
}

void videoPokerGame::drawSecoundHand()
{
    hand.DrawCardForSecoundHand();
}

void videoPokerGame::toggelHoldAtIdx(int idx)
{
    hand.toggelHoldAtIdx(idx);
}

void videoPokerGame::dealOrDraw()
{
    if(_GameState)
    {
        while (hand.handSize() < 5)
        {
            hand.addCard(deck.draw());
        }

    }
    else
    {
        hand.clear();
        deck.shuffle();
        while (hand.handSize() < 5)
        {
            hand.addCard(deck.draw());
        }
    }
}
