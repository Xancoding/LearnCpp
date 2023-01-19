#include <algorithm>
#include <array>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>

// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };

class Card
{
public:
    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };

private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card() = default;

    Card(Rank rank, Suit suit)
            : m_rank{ rank }, m_suit{ suit }
    {
    }

    void print() const
    {
        switch (m_rank)
        {
            case rank_2:        std::cout << '2';   break;
            case rank_3:        std::cout << '3';   break;
            case rank_4:        std::cout << '4';   break;
            case rank_5:        std::cout << '5';   break;
            case rank_6:        std::cout << '6';   break;
            case rank_7:        std::cout << '7';   break;
            case rank_8:        std::cout << '8';   break;
            case rank_9:        std::cout << '9';   break;
            case rank_10:       std::cout << 'T';   break;
            case rank_jack:     std::cout << 'J';   break;
            case rank_queen:    std::cout << 'Q';   break;
            case rank_king:     std::cout << 'K';   break;
            case rank_ace:      std::cout << 'A';   break;
            default:
                std::cout << '?';
                break;
        }

        switch (m_suit)
        {
            case club:          std::cout << 'C';   break;
            case diamond:       std::cout << 'D';   break;
            case heart:         std::cout << 'H';   break;
            case spade:         std::cout << 'S';   break;
            default:
                std::cout << '?';
                break;
        }
    }

    int value() const
    {
        switch (m_rank)
        {
            case rank_2:        return 2;
            case rank_3:        return 3;
            case rank_4:        return 4;
            case rank_5:        return 5;
            case rank_6:        return 6;
            case rank_7:        return 7;
            case rank_8:        return 8;
            case rank_9:        return 9;
            case rank_10:       return 10;
            case rank_jack:     return 10;
            case rank_queen:    return 10;
            case rank_king:     return 10;
            case rank_ace:      return 11;
            default:
                assert(false && "should never happen");
                return 0;
        }
    }
};

class Deck
{
public:
    using DeckType = std::array<Card, 52>;
    using Index = DeckType::size_type;

private:
    DeckType m_deck{};
    Index m_cardIndex{ 0 };

public:
    Deck()
    {
        Index index{ 0 };

        for (int suit{ 0 }; suit < Card::max_suits; ++suit)
        {
            for (int rank{ 0 }; rank < Card::max_ranks; ++rank)
            {
                m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
                ++index;
            }
        }
    }

    void print() const
    {
        for (const auto& card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);

        m_cardIndex = 0;
    }

    const Card& dealCard()
    {
        assert(m_cardIndex < m_deck.size());

        return m_deck[m_cardIndex++];
    }
};

class Player
{
private:
    int m_score{};

public:
    int drawCard(Deck& deck)
    {
        int value = deck.dealCard().value();
        m_score += value;
        return value;
    }

    int score() const
    {
        return m_score;
    }

    bool isBust() const
    {
        return (m_score > g_maximumScore);
    }

};

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                auto playerCard = player.drawCard(deck);
                std::cout << "You were dealt a " << playerCard << " and now have " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
    return false;
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    while (dealer.score() < g_minimumDealerScore)
    {
        auto dealerCard { dealer.drawCard(deck) };
        std::cout << "The dealer turned up a " << dealerCard << " and now has " << dealer.score() << '\n';
    }

    if (dealer.isBust())
    {
        std::cout << "The dealer busted!\n";
        return true;
    }
    return false;
}

bool playBlackjack(Deck& deck)
{
    Player dealer{};
    dealer.drawCard(deck);

    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    Deck deck{};

    deck.shuffle();

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}