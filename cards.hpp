#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>
#ifndef CARDS  
#define CARDS


namespace cards
{
    std::default_random_engine eng;
    enum suit
    {
        suit_first,
        hearts,
        spades,
        clubs,
        diamonds,
        suit_last
    };

    enum value
    {
        value_first,
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        value_last
    };

    class Card
    {
    public:
        Card(suit s, value v) : s_{s}, v_{v} {}

        suit Get_suit() const
        {
            return s_;
        }
        value Get_value() const
        {
            return v_;
        }

    private:
        suit s_;
        value v_;
    };

    std::vector<Card> Create_deck()
    {
        std::vector<Card> deck;
        for (int i = suit_first + 1; i != suit_last; i++)
        {
            for (int j = value_first + 1; j != value_last; ++j)
            {
                deck.push_back(Card(suit(i), value(j)));
            }
        }
        return deck;
    };

    class Deck
    {
    public:
        Deck() : deck_{Create_deck()} {}

        std::vector<Card> deal(int n)
        {
            std::vector<Card> deck_copy{deck_};
            std::shuffle(deck_copy.begin(), deck_copy.end(), eng);
            return std::vector<Card>(deck_copy.begin(), deck_copy.begin() + n);
        }

    private:
        std::vector<Card> const deck_;
    };

}


#endif