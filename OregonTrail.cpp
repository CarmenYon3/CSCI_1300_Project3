#include <iostream>
#include <iomanip>
#include "Time.h"
#include "Party.h"
#include "Store.h"
#include "Milestone.h"
#include "Milestones.h"
#include <vector>


int main(){

}

/**
 * Called if a raider attack occours, affects party stats according to the outcome of the raid
 * @param party the party taken as input (reference)
 */
void raiderAttack(Party &party){
    
}

/**
 * Called whenever the user decides to hunt, contains all probabilities for each type of animal hunted, and adjusts party stats depending 
 * on the outcome of the related game
 * asks the player how the party would like to eat, and adjusts party stats accordingly
 * adjusts time depending on if the user hunted or not
 * @param party party taken as input (reference)
 * @param time time taken as input (reference)
 */
void hunt(Party &party, Time &time){

}

/**
 * Called whenever a player has an oppertunity to shop
 * presents a menu and racks up a bill as the player selects items
 * upon exiting, the bill is subrtraced from the party stats
 * @param party party taken as input (reference)
 * @param store store taken as input (reference)
 */
void shop(Party &party, Store &store){

}

/**
 * Called when the player chooses to rest
 * adjust time and party stats accordingly
 * @param party party taken as input (reference)
 * @param time time taken as input (reference) 
 */
void rest(Party &party,Time &time){

}
/**
 * called whenever a misfortume might happen
 * adjusts party and time stats according to the misfortune that has occoured
 * @param party party taken as input (reference)
 * @param time store taken as input (reference)
 */
void mosfortune(Party &party, Time &time){

}

/**
 * called whenever a puzzle must be solved
 * @return true if the puzzle is solved, false if not
 */
bool puzzle(){

}
/**
 * Writes the score at the end of the game to a high score list
 * pass the file into a vector, sorts vector using bubble sort, rewrites file using new vector
 * file being written to will contain previous runs high scores
 * @param party party taken as input (reference)
 * @param time store taken as input (reference)
 * @param milestones milestones object taken as input (reference)
 */
void writeResults(Party &party, Time &time, Milestones &milestones){

}
/**
 * Take two vectors of scores and names as input,
 * Use bubble sort to sort the int vector, and perform the same operations on name to maintain the same pairings
 * @param scores vec of high scores to be sorted
 * @param name vec of names to be sorted
 */
void bubbleSortHighScore(std::vector<int> &scores, std::vector<std::string> &name){

}