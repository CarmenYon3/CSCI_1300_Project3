#include "Milestone.h"
#include <iostream>

/**
 * Default constructor for the milestone class. Sets the initial miles traveled to 0 and each milestone name and value to and empty string and 0
 */
Milestone::Milestone(){
    milesTraveled = 0;
    for(int i = 0; i < NUM_MILESTONES; i++){
        milestoneDist[i] = 0;
        milestoneName[i] = "";
    }
}

/**
 * Takes a name of a file as a parameter, and reads pre-formatted data containing milestone names and distances, and stores it in
 * the member arrays. Includes specific return values if the file-reading process fails in some way.
 * @param fileName name of file to be read from
 * @return -1 if filename can't be found, 0 if success, or 1 if the file is formatted incorrectly
 */
int Milestone::readMileStones(std::string fileName){

}

/**
 * @return number of miles traveled
 */
int Milestone::getMilesTraveled(){
    return milesTraveled;
}

/**
 * sets the number of miles traveled
 * @param miles the number of miles traveled
 */
void Milestone::setMilesTraveled(int miles){
    milesTraveled = miles;
}
/**
 * @return the distance to the next milestone
 */
int Milestone::getNextMilestoneDist(){
    int milestoneIndex = 0;
    for(int i = 0; i < NUM_MILESTONES; i++){
        if(milesTraveled < milestoneDist[i]){
            milestoneIndex = i;
        }

    return milestoneDist[milestoneIndex] - milesTraveled;
    }
}

/**
 * @return the name of the next milestone
 */
std::string Milestone::getNextMilestoneName(){
    int milestoneIndex = 0;
    for(int i = 0; i < NUM_MILESTONES; i++){
        if(milesTraveled < milestoneDist[i]){
            milestoneIndex = i;
        }
    return milestoneName[milestoneIndex];
}