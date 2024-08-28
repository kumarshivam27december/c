#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Card values
enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10, ACE = 11 };
const char* RankStrings[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

// Card structure
struct Card {
    Rank rank;
    // Constructor to create a card with a given rank
    Card(Rank r) : rank(r) {}
};

// Deck class
class Deck {
private:
    std::vector<Card> cards;
public:
    Deck() {
        for (int i = 0; i < 4; ++i) {
            for (int r = TWO; r <= ACE; ++r) {
                cards.emplace_back(static_cast<Rank>(r));
            }
        }
        std::srand(std::time(0));
        std::random_shuffle(cards.begin(), cards.end());
    }
    
    Card deal() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }
    
    bool empty() const {
        return cards.empty();
    }
};

// Function to calculate hand value
int calculateHandValue(const std::vector<Card>& hand) {
    int value = 0;
    int aceCount = 0;
    
    for (const auto& card : hand) {
        value += card.rank;
        if (card.rank == ACE) {
            ++aceCount;
        }
    }
    
    while (value > 21 && aceCount > 0) {
        value -= 10;
        --aceCount;
    }
    
    return value;
}

// Function to print hand
void printHand(const std::vector<Card>& hand, const std::string& owner) {
    std::cout << owner << "'s hand: ";
    for (const auto& card : hand) {
        std::cout << RankStrings[card.rank - 2] << " ";
    }
    std::cout << "(Value: " << calculateHandValue(hand) << ")\n";
}

// Main game function
void playBlackjack() {
    Deck deck;
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;

    // Initial deal
    playerHand.push_back(deck.deal());
    dealerHand.push_back(deck.deal());
    playerHand.push_back(deck.deal());
    dealerHand.push_back(deck.deal());

    // Player's turn
    bool playerBusted = false;
    char choice;
    
    while (true) {
        printHand(playerHand, "Player");
        if (calculateHandValue(playerHand) > 21) {
            std::cout << "Player busts!\n";
            playerBusted = true;
            break;
        }
        
        std::cout << "Do you want to (h)it or (s)tay? ";
        std::cin >> choice;
        if (choice == 'h') {
            playerHand.push_back(deck.deal());
        } else if (choice == 's') {
            break;
        } else {
            std::cout << "Invalid choice. Please enter 'h' or 's'.\n";
        }
    }

    // Dealer's turn
    if (!playerBusted) {
        printHand(dealerHand, "Dealer");
        while (calculateHandValue(dealerHand) < 17) {
            dealerHand.push_back(deck.deal());
            printHand(dealerHand, "Dealer");
        }
        
        int playerValue = calculateHandValue(playerHand);
        int dealerValue = calculateHandValue(dealerHand);
        
        if (dealerValue > 21) {
            std::cout << "Dealer busts! Player wins!\n";
        } else if (playerValue > dealerValue) {
            std::cout << "Player wins!\n";
        } else if (playerValue < dealerValue) {
            std::cout << "Dealer wins!\n";
        } else {
            std::cout << "It's a tie!\n";
        }
    }
}

int main() {
    std::cout << "Welcome to Blackjack!\n";
    playBlackjack();
    return 0;
}
