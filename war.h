#ifndef WAR_H
#define WAR_H
/*
  This runWar function runs a game of war between 2 automated players
  and returns the number of rounds (both put a card down 
  once per round) until someone won.  An integer is given 
  as an upper limit to how many rounds a game can go on for.
*/
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <stack>
#include <queue>

#include "deck.h"

using namespace std;

int runWar(unsigned int limit) {

    Deck full_deck;
    queue<Card> queue1, queue2;

    //split deck
    for (int i = 0; i < 52; i++) {
        Card card_from_full_deck = full_deck.getTopCard();
        if (i % 2 == 0) {
            queue1.push(card_from_full_deck);
        } else {
            queue2.push(card_from_full_deck);
        }
    }

    Deck deck1(queue1);
    Deck deck2(queue2);

    unsigned int comparison_counter = 0;
    while (comparison_counter < limit && deck1.size() > 0 && deck2.size() > 0) {

        //// << "Deck1 size: " << deck1.size() << "\t Deck2 size: " << deck2.size() << "\n";
        //// << "Round: " << comparison_counter << endl;

        //compare cards
        Card card1 = deck1.getTopCard();
        Card card2 = deck2.getTopCard();

        //// << "Deck1 card: " << card1 << "\nDeck2 card: " << card2 << "\n";

        //if either player has only one card left, their deck will empty when they play that card, ending the game
        if (deck1.size() == 1) {
            deck1.getTopCard();
        } else if (deck2.size() == 1) {
            deck2.getTopCard();
        } else {

            unsigned int rank1 = card1.getRank();
            unsigned int rank2 = card2.getRank();
            if (rank1 > rank2) {
                //// << "Deck1 Wins!\n\n";
                deck1.addCard(card1);
                deck1.addCard(card2);
            } else if (rank2 > rank1) {
                //// << "Deck2 Wins!\n\n";
                deck2.addCard(card1);
                deck2.addCard(card2);
            } else if (rank2 == rank1) {
                // << "War!\n\n";
                vector<Card> cards_out;
                cards_out.push_back(card1);
                cards_out.push_back(card2);

                bool in_war = true;
                /* need 4 cards for a round of war; as per the rules, if a deck is empty at any time, that deck loses
                   because of this, each deck needs at least 5 cards to have an unempty deck after the war
                 */

                while (in_war) {
                    if (deck1.size() > 4 && deck2.size() > 4) {
                        for (int i = 0; i < 3; i++) {
                            cards_out.push_back(deck1.getTopCard());
                            cards_out.push_back(deck2.getTopCard());
                        }

                        Card war_card1 = deck1.getTopCard();
                        Card war_card2 = deck2.getTopCard();

                        cards_out.push_back(war_card1);
                        cards_out.push_back(war_card2);

                        //// << "Warcard1: " << war_card1 << "\nWarcard2: " << war_card2 << endl;
                        // << "Cards on table: " << cards_out.size() << endl;
                        comparison_counter++;
                        if (war_card1.getRank() > war_card2.getRank()) {
                            // << "Deck1 Wins!\n";
                            for (unsigned int i = 0; i < cards_out.size(); i++) {
                                deck1.addCard(cards_out[i]);
                            }
                            in_war = false;
                        } else if (war_card2.getRank() > war_card1.getRank()) {
                            // << "Deck2 Wins!\n";
                            for (unsigned int i = 0; i < cards_out.size(); i++) {
                                deck2.addCard(cards_out[i]);
                            }
                            in_war = false;
                        }

                    } else if (deck1.size() <= 4) {
                        //Deck1 would have emptied during the war, so we empty it
                        for (unsigned int i = 0; i < deck1.size(); i++) {
                            deck1.getTopCard();

                        }
                        in_war = false;
                    } else if (deck2.size() <= 4) {
                        for (unsigned int i = 0; i < deck2.size(); i++) {
                            deck2.getTopCard();
                        }
                        in_war = false;
                    }

                }

            }
        }
        comparison_counter++;
    }

    if (deck1.size() == 0) {
        // << "Deck2 Wins the Game!" << endl;
    } else if (deck2.size() == 0) {
        // << "Deck1 Wins the Game!" << endl;
    } else {
        // << "Draw!" << endl;
    }


    return comparison_counter;
}

#endif
