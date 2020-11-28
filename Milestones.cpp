// Peter Ashmore & Michael Yon

#include "Milestones.h"
#include <iostream>
#include <fstream>
#include <string>

/**
 * Default constructor for the milestone class. Sets the initial miles traveled to 0 and each milestone name and value to and empty string and 0
 */
Milestones::Milestones(){
    milesTraveled = 0;
    for(int i = 0; i < NUM_MILESTONES; i++){
        milestones[i].setDistance(0);
        milestones[i].setName("");
    }
}

/**
 * Takes a name of a file as a parameter, and reads pre-formatted data containing milestone names and distances, and stores it in
 * the member array of milestones. Includes specific return values if the file-reading process fails in some way.
 * @param fileName name of file to be read from
 * @return -1 if filename can't be found, 0 if success, or 1 if the file is formatted incorrectly
 */
int Milestones::readMileStones(std::string fileName){
    std::string line = "";
    std::ifstream inFile;
    inFile.open(fileName);

    if(inFile.fail() == false){
        int count = 0;
        while(getline(inFile,line)){
            milestones[count].setName(line);
            getline(inFile,line);
            milestones[count].setDistance(stoi(line));
            count++;
        }
        return 0;
    }
    else{
        return -1;
    }
}

/**
 * @return number of miles traveled
 */
int Milestones::getMilesTraveled(){
    return milesTraveled;
}

/**
 * sets the number of miles traveled
 * @param miles the number of miles traveled
 */
void Milestones::setMilesTraveled(int miles){
    milesTraveled = miles;
}
/**
 * @return the distance to the next milestone
 */
int Milestones::getNextMilestoneDist(){
    int milestoneIndex = 0;
    for(int i = 0; i < NUM_MILESTONES; i++){
        if(milesTraveled < milestones[i].getDistance()){
            milestoneIndex = i;
            break;
        }
    }
    return milestones[milestoneIndex].getDistance() - milesTraveled;
}

/**
 * @return the name of the next milestone
 */
std::string Milestones::getNextMilestoneName(){
    int milestoneIndex = 0;
    for(int i = 0; i < NUM_MILESTONES; i++){
        if(milesTraveled < milestones[i].getDistance()){
            milestoneIndex = i;
            break;
        }
    }
    return milestones[milestoneIndex].getName();
}

std::string Milestones::getNameAt(int index){
    return milestones[index].getName();
}

int Milestones::getDistAt(int index){
    return milestones[index].getDistance();
}

// int main(){
//     Milestones test = Milestones();
//     std::cout << test.readMileStones("milestones.txt") << std::endl;
//     for(int i = 0; i < 14; i++){
//         std::cout << test.getNameAt(i) << std::endl;
//     }
// }
