// Peter Ashmore & Michael Yon

#include <iostream>
#include <iomanip>
#include "Time.h"
#include "Party.h"
#include "Store.h"
#include "Milestones.h"
#include <vector>
#include <cstdlib>




int randomNumberGenerator (int rand_min, int rand_max){
    int rng = rand() % rand_max + rand_min;
    return rng;
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
    if(randomNumberGenerator(0,1))
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
 * called whenever a misfortune might happen
 * adjusts party and time stats according to the misfortune that has occoured
 * @param party party taken as input (reference)
 * @param time store taken as input (reference)
 */
void misfortune(Party &party, Time &time){

}

/**
 * called whenever a puzzle must be solved
 * @return true if the puzzle is solved, false if not
 */
bool puzzle(){
    for(int i = 0; i < 3; i++){
        std::cout << "Pick a number between 1 and 10" << std::endl;
        int temp;
        std::cin >> temp;
        int temp1 = randomNumberGenerator(0,10);
        if(temp == temp1){
            std::cout << "num was " << temp1 << std::endl;
            return true;
        }
        else{
            std::cout << "try again stinky" << std::endl;
            std::cout << "num was " << temp1 << std::endl;
        }
    }
    return false;
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
    bool swap;
    for(int i = 0; i < scores.size()-1; i++){
        for(int j = 0; j < scores.size()-i-1; j++){
                if(scores[j] > scores[j+1]){
                    int temp1 = scores[j];
                    std::string temp2 = name[j];
                    scores[j] = scores[j+1];
                    name[j] = name[j+1];
                    scores[j+1] = temp1;
                    name[j+1]  = temp2;
            }
        }
    }
}

/**
 * Takes a minimum and maximum value and returns a random number within that range
 * @param rand_min minimum value of random number
 * @param rand_max maximum value of random number
 * @return the number generated 
*/

int main(){

}