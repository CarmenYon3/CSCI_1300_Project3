// Peter Ashmore & Michael Yon

#include "Milestone.h"

/**
 * Default constructor for milestone
 * sets name and dist to 0
 */
Milestone::Milestone(){
    name = "";
    distance = 0;
}
/**
 * Parameterized constductor for milestone
 * @param distance distance to be set 
 * @param name name to be set
 */
Milestone::Milestone(int distance, std::string name){
    this->distance = distance;
    this->name = name;

}
/**
 * @return distance of the milestone
 */
int Milestone::getDistance(){
    return distance;
}

/**
 * @return name of the milestone
 */
std::string Milestone::getName(){
    return name;
}
/**
 * setter for distance
 * @param distance distance to be set
 */
void Milestone::setDistance(int distance){
    this->distance = distance;
}
/**
 * setter for name 
 * @param name name to be set
 */
void Milestone::setName(std::string name){
    this->name = name;
}