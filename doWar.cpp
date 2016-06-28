#include <iostream>
#include <map>

/*
  The file implements main to simulate 100000 games of war.  It should print out
  a histogram of the game lengths from 0 to 1000 rounds (ok to have less detail)
  as well as the average game length.
*/

#include "deck.h"
#include "war.h"

using namespace std;

int main() {
    srand(time(NULL));

    //Map for storing round number distribution
    map<int, int>histogram;

    //how many games to run
    int num_games = 1000;
    int increment = num_games / 50;
    for(int i = increment; i <= num_games; i = i + increment){
        histogram[i] = 0;
    }

    int total_rounds = 0;
    for(int i = 0; i < num_games; i++){
        int num_rounds = runWar(1000);
        total_rounds = total_rounds + num_rounds;

        map<int, int>::iterator it;
        for(it = histogram.begin(); it != histogram.end(); it++){
            if(num_rounds <= it->first){
                it->second++;
                break;
            }
        }
    }

    double average = total_rounds / num_games;

    //output histo results
    map<int, int>::iterator it;
    for(it = histogram.begin(); it != histogram.end(); it++){
        cout << it->first - increment + 1 << " - " << it->first <<  ":\t" << it->second << ":\t";
        for(int i = 0; i < it->second; i++){
            cout << "*";
        }
        cout << endl;
    }

    cout << "Average: " << average << endl;

    return 0;

}
