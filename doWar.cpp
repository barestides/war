#include <iostream>

/*
  The file implements main to simulate 100000 games of war.  It should print out
  a histogram of the game lengths from 0 to 1000 rounds (ok to have less detail)
  as well as the average game length.
*/

#include "deck.h"
#include "war.h"

using namespace std;

int main() {
    // Fill in code here!
    srand(time(0));
    /*Deck d;
    for (int i = 51; i >= 0; i--) {
        cout << d.size() << "\t" << d.getTopCard() << endl;

    }*/
    runWar(1000);
    return 0;

}
