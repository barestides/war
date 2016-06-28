#ifndef DECK_H
#define DECK_H
/*
  The Deck class implements a random deck of 52 cards.
*/
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <queue>
#include <vector>
#include <ctime>

#include "card.h"

using namespace std;

class Deck {
public:

    //create normal deck of all 52 cards
    Deck() {
        //create deck, unshuffled
        vector<Card> vector_deck;
        for (unsigned int i = 1; i <= 13; i++) {
            vector_deck.push_back(Card(DIAMONDS, i));
            vector_deck.push_back(Card(HEARTS, i));
            vector_deck.push_back(Card(SPADES, i));
            vector_deck.push_back(Card(CLUBS, i));
        }

        //shuffle deck
        for (unsigned int i = 0; i < vector_deck.size(); i++) {
            int j = rand() % (int) vector_deck.size();
            Card temp = vector_deck[j];
            vector_deck[j] = vector_deck[i];
            vector_deck[i] = temp;
        }

        for (unsigned int i = 0; i < vector_deck.size(); i++) {
            d.push(vector_deck[i]);
        }

    }

    //create deck from queue of cards
    Deck(queue<Card> cards){
        d = cards;
    }

    Card getTopCard() {
        Card top = d.front();
        d.pop();
        return top;

    }

    unsigned int size() const {
        // Return the size of the rest of the deck.
        return (unsigned int) d.size();
    }

    void addCard(Card card){
        d.push(card);
    }


private:
    queue<Card> d;    // Hint hint!
    unsigned int num_cards;


};

#endif
