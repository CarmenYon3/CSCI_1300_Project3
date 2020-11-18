#include <iostream>
#include <iomanip>
#include "Time.h"
#include "Party.h"
#include "Store.h"
#include "Milestone.h"


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