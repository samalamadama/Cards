
#include "cards.hpp"
#include <iostream>
#include<cmath>

int main()
{
    (cards::eng).seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::vector<cards::Card> dealt;
    cards::Deck deck;
    int n_aces;
    int n_trice_aces{0};
    int const iterations{100000000};
    auto IsAce{[=](int acc, cards::Card const &card)
               {
                   return acc + (card.Get_value() == cards::ace);
               }};

    for (int i{0}; i != iterations; ++i)
    {
        dealt = deck.deal(5);
        n_aces = std::accumulate(dealt.begin(), dealt.end(), 0, IsAce);
        if (n_aces == 3)
        {
            ++n_trice_aces;
        }
        if(i == iterations/5 || i==iterations*2/5 || i==iterations*3/5 || i==iterations*4/5){
            std::cout<<"progress: "<< i*100/iterations <<" %"<<'\n';
        }
    }
    double probability = static_cast<double>(n_trice_aces)/iterations*100;
    std::cout<<probability<<" +/- "<<(1/std::sqrt(iterations))*100 <<'\n';
}