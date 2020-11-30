// Peter Ashmore & Michael Yon

#include <iostream>
#include <iomanip>
#include "Time.h"
#include "Party.h"
#include "Store.h"
#include "Milestones.h"
#include <vector>
#include <cstdlib>
#include <cmath>



bool puzzle();

int randomNumberGenerator (int rand_min, int rand_max){
    int rng = rand() % rand_max + rand_min;
    return rng;
}

/**
 * Called when a raider attack might occour, affects party stats according to the outcome of the raid
 * @param party the party taken as input (reference)
 */
void raiderAttack(Party &party,Milestones & milestones){

    double miles = milestones.getMilesTraveled(); //gets miles so the expression is simpler
    int probability = ((( pow(((miles / 100.0)-4.0),2) + 72.0 ) / ( pow(((miles / 100.0)-4.0),2) + 12.0 )) -1.0) / 0.1 ; //calculated probability

    if(randomNumberGenerator(1,100) <= probability){//raider attack happens
        while(true){
            std::cout << "RIDERS AHEAD! THEY LOOK HOSTILE!" << std::endl;
            std::cout << "(1) RUN" << std::endl;
            std::cout << "(2) ATTACK" << std::endl;
            std::cout << "(3) SURRENDER" << std::endl;

            int choice;
            std::cin >> choice;

            if(choice == 1){
                std::cout << "YOUR PARTY ESCAPES, BUT IN THE HURRY TO FLEE, YOU LEAVE BEHIND 1 OXEN, 10LBS OF FOOD, AND 1 WAGON PART" << std::endl;
                party.setOxen(party.getOxen() - 1);//ox -1
                party.setFood(party.getFood() - 10);//food -10

                //lose 1 wagon part
                if(party.getAxles() > 0){
                    party.setAxles(party.getAxles() -1);
                }
                else if(party.getTongues() > 0){
                    party.setTongues(party.getTongues() -1);                  
                }
                else if(party.getWheels() > 0){
                    party.setWheels(party.getWheels() -1);                  
                }

                break;
            }
            else if(choice == 2){
                std::cout << "YOU MUST WIN A PUZZLE TO WIN THE BATTLE" << std:: endl;
                if(puzzle()){
                    std::cout << "YOU WON THE BATTLE, AND GAINED 50 LBS OF FOOD AND 50 BULLETS" << std:: endl;
                    party.setFood(party.getFood() + 50);
                    party.setBullets(party.getBullets() + 50);
                    break;
                }
                else{

                    std::cout << "YOU LOST THE BATTLE, AND LOST A QUARTER OF YOUR CASH AND 50 BULLETS" << std:: endl;
                    if(party.getBullets() >= 50){
                        party.setBullets(party.getBullets() - 50);
                    }
                    else{
                        party.setBullets(0);
                    }

                    party.setMoney(party.getMoney() * 0.75);
                    break;
                }
            }
            else if(choice == 3){
                std::cout << "YOU SURRENDER, AND LOSE A QUARTER OF YOUR CASH" << std:: endl;
                party.setMoney(party.getMoney() * 0.75);
                break;
            }
            else{
                std::cout << "Invalid input, try again" << std::endl;
                continue;
            }
        }
    }

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
    int food = 0;
    if(randomNumberGenerator(0,1) == 0){    
        while(true){
            std::cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT! DO YOU WANT TO HUNT: " << std::endl;
            std::cout << "(1) YES, (2) NO" << std::endl;
            int temp; 
            std::cin >> temp;
            if(temp == 1){
                if(party.getBullets() >= 10){
                    std::cout << "YOU MUST SOLVE A PUZZLE TO HAVE A SUCCESSFUL HUNT: " << std::endl;
                    bool outcome = puzzle();
                    if(outcome){
                        std::cout << "THE HUNT WAS SUCCESSFUL" << std::endl;
                        std::cout << "YOU USED 10 BULLETS AND GOT 5 LBS OF FOOD" << std::endl;
                        party.setBullets(party.getBullets() - 10);
                        food += 5;
                        break;
                    }
                    else{
                        std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                        break;
                    }
                }
                else{
                    std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                    break;
                }
            }
            else if(temp == 2){
                break;
            }
            else{
                std::cout << "invalid input, try again" << std::endl;
                continue;
            }
        }
    }

    if(randomNumberGenerator(0,4) == 0){    
        while(true){
            std::cout << "YOU GOT LUCKY! YOU ENCOUNTERED A FOX! DO YOU WANT TO HUNT: " << std::endl;
            std::cout << "(1) YES, (2) NO" << std::endl;
            int temp; 
            std::cin >> temp;
            if(temp == 1){
                if(party.getBullets() >= 10){
                    std::cout << "YOU MUST SOLVE A PUZZLE TO HAVE A SUCCESSFUL HUNT: " << std::endl;
                    bool outcome = puzzle();
                    if(outcome){
                        std::cout << "THE HUNT WAS SUCCESSFUL" << std::endl;
                        std::cout << "YOU USED 8 BULLETS AND GOT 10 LBS of FOOD" << std::endl;
                        party.setBullets(party.getBullets() - 8);
                        food += 10;
                        break;
                    }
                    else{
                        std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                        break;
                    }
                }
                else{
                    std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                    break;
                }
            }
            else if(temp == 2){
                break;
            }
            else{
                std::cout << "invalid input, try again" << std::endl;
                continue;
            }
        }
    }

    if(randomNumberGenerator(1,100) <= 15){    
        while(true){
            std::cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER! DO YOU WANT TO HUNT: " << std::endl;
            std::cout << "(1) YES, (2) NO" << std::endl;
            int temp; 
            std::cin >> temp;
            if(temp == 1){
                if(party.getBullets() >= 10){
                    std::cout << "YOU MUST SOLVE A PUZZLE TO HAVE A SUCCESSFUL HUNT: " << std::endl;
                    bool outcome = puzzle();
                    if(outcome){
                        std::cout << "THE HUNT WAS SUCCESSFUL" << std::endl;
                        std::cout << "YOU USED 5 BULLETS AND GOT 60 LBS of FOOD" << std::endl;
                        party.setBullets(party.getBullets() - 5);
                        food += 60;
                        break;
                    }
                    else{
                        std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                        break;
                    }
                }
                else{
                    std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                    break;
                }
            }
            else if(temp == 2){
                break;
            }
            else{
                std::cout << "invalid input, try again" << std::endl;
                continue;
            }
        }
    }

    if(randomNumberGenerator(1,100) <= 7){    
        while(true){
            std::cout << "YOU GOT LUCKY! YOU ENCOUNTERED A BEAR! DO YOU WANT TO HUNT: " << std::endl;
            std::cout << "(1) YES, (2) NO" << std::endl;
            int temp; 
            std::cin >> temp;
            if(temp == 1){
                if(party.getBullets() >= 10){
                    std::cout << "YOU MUST SOLVE A PUZZLE TO HAVE A SUCCESSFUL HUNT: " << std::endl;
                    bool outcome = puzzle();
                    if(outcome){
                        std::cout << "THE HUNT WAS SUCCESSFUL" << std::endl;
                        std::cout << "YOU USED 10 BULLETS AND GOT 200 LBS of FOOD" << std::endl;
                        party.setBullets(party.getBullets() - 10);
                        food += 200;
                        break;
                    }
                    else{
                        std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                        break;
                    }
                }
                else{
                    std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                    break;
                }
            }
            else if(temp == 2){
                break;
            }
            else{
                std::cout << "invalid input, try again" << std::endl;
                continue;
            }
        }
    }

    if(randomNumberGenerator(1,100) <= 5){    
        while(true){
            std::cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE! DO YOU WANT TO HUNT: " << std::endl;
            std::cout << "(1) YES, (2) NO" << std::endl;
            int temp; 
            std::cin >> temp;
            if(temp == 1){
                if(party.getBullets() >= 10){
                    std::cout << "YOU MUST SOLVE A PUZZLE TO HAVE A SUCCESSFUL HUNT: " << std::endl;
                    bool outcome = puzzle();
                    if(outcome){
                        std::cout << "THE HUNT WAS SUCCESSFUL" << std::endl;
                        std::cout << "YOU USED 12 BULLETS AND GOT 500 LBS of FOOD" << std::endl;
                        party.setBullets(party.getBullets() - 12);
                        food += 500;
                        break;
                    }
                    else{
                        std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                        break;
                    }
                }
                else{
                    std::cout << "THE HUNT WAS UNSUCCESSFUL" << std::endl;
                    break;
                }
            }
            else if(temp == 2){
                break;
            }
            else{
                std::cout << "invalid input, try again" << std::endl;
                continue;
            }
        }
    }

    std::cout << "HOW WOULD YOU LIKE TO EAT?" << std::endl;
    std::cout << "(1) POORLY: 2 lbs food, per person" << std::endl;
    std::cout << "(2) MODERATELY: 3 lbs food, per person" << std::endl;
    std::cout << "(3) WELL: 5 lbs food, per person" << std::endl;
    
    while(true){
        int choice;
        std::cin >> choice;
        if(choice == 1){
            party.setFood(party.getFood() - 2);
            for(int i = 0; i < 4; i++){
                if(party.getPartyLifeAt(i) == true){
                    party.setFood(party.getFood() - 2);
                }
            }
            break;
        }
        else if(choice == 2){
            party.setFood(party.getFood() - 3);
            for(int i = 0; i < 4; i++){
                if(party.getPartyLifeAt(i) == true){
                    party.setFood(party.getFood() - 3);
                }
            }
            break;
        }
        else if(choice == 3){
            party.setFood(party.getFood() - 5);
            for(int i = 0; i < 4; i++){
                if(party.getPartyLifeAt(i) == true){
                    party.setFood(party.getFood() - 5);
                }
            }
            break;
        }
        else{
            std::cout << "invalid input, try again" << std::endl;
            continue;
        }
    }

    std::cout << "YOU HAVE GATHERED " << food << " LBS OF FOOD FROM HUNTING" << std::endl;

    if((food + party.getFood()) > 1000){
        std::cout << "YOUR WAGON DOES NOT HAVE ENOUGH ROOM. YOU HAVE 1000 LBS OF FOOD, AND YOU LEAVE THE REST BEHIND" << std::endl;
        party.setFood(1000); 
    }
    else{
        std::cout << "YOU NOW HAVE " << food  + party.getFood() << " LBS OF FOOD" << std::endl;
        party.setFood(food + party.getFood()); 
    }

}

/**
 * Called whenever a player has an oppertunity to shop
 * presents a menu and racks up a bill as the player selects items
 * upon exiting, the bill is subrtraced from the party stats
 * @param party party taken as input (reference)
 * @param store store taken as input (reference)
 */
void shop(Party &party, Store &store){

    double oxenBill = 0.00;
    double foodBill = 0.00;
    double bulletsBill = 0.00;
    double miscSuppliesBill = 0.00;
    double totalBill = oxenBill + foodBill + bulletsBill + miscSuppliesBill;
    int choice = 0;

    while (true){
        std::cout << "============================================" << std::endl;
        std::cout << "               General Store                " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "1. Oxen                           $" << oxenBill << std::endl;
        std::cout << "2. Food                           $" << foodBill << std::endl;
        std::cout << "3. Bullets                        $" << bulletsBill << std::endl;
        std::cout << "4. Miscellaneous Supplies         $" << miscSuppliesBill << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "                      Total bill: $" << totalBill << std::endl;
        std::cout << std::endl;
        std::cout << "Amount you have: " << party.getMoney() << std::endl;
        std::cout << std::endl;
        std::cout << "Which item would you like to buy?" << std::endl;
        std::cin >> choice;

        if (choice == 1){


        }
        else if (choice == 2){


        }
        else if (choice == 3){


        }
        else if (choice == 4){


        }
        else if (choice == 5){

            std::cout << "Total bill: $" << totalBill << std::endl;
            party.setMoney(party.getMoney() - totalBill);
            break;
        }
        else{

            std::cout << "Invalid input" << std::endl;
            continue;
        }
    }
    
}

/**
 * Called when the player chooses to rest
 * adjust time and party stats accordingly
 * @param party party taken as input (reference)
 * @param time time taken as input (reference) 
 */
void rest(Party &party,Time &time){
    int days = randomNumberGenerator(1,3);//generates a random number between 1 and 3
    std::cout << "YOU REST FOR " << days << " DAYS" << std::endl;//displays how many days you reat for

    for(int i = 0; i < days; i++){//loop through that number of days to adjust stats

        party.setFood(party.getFood() - 3);//food subtracted for player each day

        for(int j = 0; j < 4; j++){
            if(party.getPartyLifeAt(j) == true){
                party.setFood(party.getFood() - 3);//food subtracted for each party member each day
            }
        }

        time.addDays(1);//incraments the days
    }
}

/**
 * called when the player chooses to continue
 * adjusts time and party stats accordingly
 * @param party party taken as input
 * @param time time taken as input
 * @param milestones milestones taken as input
 */
void continueOn(Party &party, Time &time,Milestones &milestones){
    int distance = randomNumberGenerator(70,71); //generates a random number between 70 and 140 (distance traveled)
    int foodUsed = 0;

    for(int i = 0; i < 14; i++){
        foodUsed += 3; //food eaten by player

        for(int j = 0; j < 4; j++){
            if(party.getPartyLifeAt(j) == true){
                foodUsed += 3;//food eaten by each party member
            }
        }
    }
    
    milestones.setMilesTraveled(milestones.getMilesTraveled() + distance);//adds the distance to the total miles traveled
}
/**
 * called whenever a misfortune might happen
 * adjusts party and time stats according to the misfortune that has occoured
 * @param party party taken as input (reference)
 * @param time store taken as input (reference)
 * @return true if the game can continue, false if otherwise
 */
bool misfortune(Party &party, Time &time){
    if(randomNumberGenerator(1,100) <= 40){//misfortune occours

        int choice = randomNumberGenerator(1,3);//possibilities for misfortunes
        int diseaseNum = randomNumberGenerator(1,5); //possibilities for diseases
        std::string disease = "";
        switch(diseaseNum){
            case 1:
                disease = "CHOLERA";
                break;
            case 2:
                disease = "DYSENTARY";
                break;
            case 3:
                disease = "TYPHIOD";
                break;
            case 4: 
                disease = "MEASLES";
                break;
            case 5:
                disease = "FEVER";
                break;
            default:
                disease = "DOO DOO";
                break;
        }

        if(choice == 3){//disease
            int patient = randomNumberGenerator(0,5);//random number between 0 and 4
            if(patient == 4){//you catch some disease
                std::cout << "YOU HAVE CAUGHT " << disease << std::endl;
                    if(party.getMedKits() > 0){
                        std::cout << "YOU USE A MEDKIT" << std::endl;
                        if(randomNumberGenerator(0,2) == 0){//50% change
                            std::cout << "YOU DIE OF " << disease << std::endl;
                            return false;
                        }
                        else{
                            std::cout << "YOU SURVIVE" << std::endl;
                            return true;
                        }
                    }
                    else{
                        while(true){
                            std::cout << "YOU CAN EITHER:" << std::endl;
                            std::cout << "(1) REST" << std::endl;
                            std::cout << "(2) PUSH ON" << std::endl;

                            int in;
                            std::cin >> in;

                            if(in == 1){

                                for(int i = 0; i < 3; i++){//loop through that number of days to adjust stats

                                    party.setFood(party.getFood() - 3);//food subtracted for player each day

                                    for(int j = 0; j < 4; j++){
                                        if(party.getPartyLifeAt(j) == true){
                                            party.setFood(party.getFood() - 3);//food subtracted for each party member each day
                                        }
                                    }

                                    time.addDays(1);//incraments the days
                                }

                                if(randomNumberGenerator(1,10) <= 3){//30%change
                                    std::cout << "YOU DIE OF " << disease << std::endl;
                                    return false;
                                }
                                else{
                                    std::cout << "YOU SURVIVE" << std::endl;
                                    return true;
                                }
                                
                            }
                            else if(in == 2){
                                if(randomNumberGenerator(1,10) <= 7){//70%change
                                    std::cout << "YOU DIE OF " << disease << std::endl;
                                    return false;
                                }
                                else{
                                    std::cout << "YOU SURVIVE" << std::endl;
                                    return true;
                                }
                            }
                            else{
                                std::cout << "Invalid input, try again" << std::endl;
                            }
                        }

                    }
            }
            else{//a party member catches some disease
                std::cout << party.getPartyMembersAt(choice) << " HAS CAUGHT " << disease << std::endl;      

                if(party.getMedKits() > 0){
                        std::cout << "YOU USE A MEDKIT" << std::endl;
                        if(randomNumberGenerator(0,2) == 0){//50% change
                            std::cout << party.getPartyMembersAt(choice) << "DIES OF " << disease << std::endl;
                            party.setPartyLifeAt(choice,false);
                            return true;
                        }
                        else{
                            std::cout << party.getPartyMembersAt(choice) << " SURVIVES" << std::endl;
                            return true;
                        }
                    }
                    else{
                        while(true){
                            std::cout << "YOU CAN EITHER:" << std::endl;
                            std::cout << "(1) REST" << std::endl;
                            std::cout << "(2) PUSH ON" << std::endl;

                            int in;
                            std::cin >> in;

                            if(in == 1){

                                for(int i = 0; i < 3; i++){//loop through that number of days to adjust stats

                                    party.setFood(party.getFood() - 3);//food subtracted for player each day

                                    for(int j = 0; j < 4; j++){
                                        if(party.getPartyLifeAt(j) == true){
                                            party.setFood(party.getFood() - 3);//food subtracted for each party member each day
                                        }
                                    }

                                    time.addDays(1);//incraments the days
                                }

                                if(randomNumberGenerator(1,10) <= 3){//30%change
                                    std::cout << party.getPartyMembersAt(choice) << "DIES OF " << disease << std::endl;
                                    party.setPartyLifeAt(choice,false);
                                    return true;
                                }
                                else{
                                    std::cout << party.getPartyMembersAt(choice) << "SURVIVES" << std::endl;
                                    return true;
                                }
                                
                            }
                            else if(in == 2){
                                if(randomNumberGenerator(1,10) <= 7){//70%change
                                    std::cout << party.getPartyMembersAt(choice) << "DIES OF " << disease << std::endl;
                                    party.setPartyLifeAt(choice,false);
                                    return true;
                                }
                                else{
                                    std::cout << party.getPartyMembersAt(choice) << "SURVIVES" << std::endl;
                                    return true;
                                }
                            }
                            else{
                                std::cout << "Invalid input, try again" << std::endl;
                            }
                        }

                    }

            }
        }
        else if(choice == 2){//oxen dies
            if(party.getOxen() > 1){//there are some oxen left
                party.setOxen(party.getOxen() - 1);
                std::cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << party.getOxen() << " OXEN LEFT" << std::endl;
                return true;
            }
            else{//if there arent any oxen left
                std::cout << "OH NO! ONE OF THE OXEN HAS DIED! YOU HAVE " << party.getOxen() << " OXEN LEFT" << std::endl;
                return false;
            }
        }
        else if(choice == 1){// Wheel/Axle/Tongue breaks
            int partNum = randomNumberGenerator(1,3);
            if(partNum == 1){
                std::cout << "OH NO! ONE OF YOUR WHEELS IS BROKEN!" << std::endl;
                if(party.getWheels() > 0){
                    std::cout << "YOU USE A SPARE WHEEL" << std::endl;
                    party.setWheels(party.getWheels() - 1);
                    return true;
                }
                else{
                    std::cout << "YOU HAVE NO SPARE PARTS" << std::endl;
                    return false;
                }

            }
            else if(partNum == 2){
                std::cout << "OH NO! ONE OF YOUR AXLES IS BROKEN!" << std::endl;
                if(party.getAxles() > 0){
                    std::cout << "YOU USE A SPARE AXLE" << std::endl;
                    party.setAxles(party.getAxles() - 1);
                    return true;
                }
                else{
                    std::cout << "YOU HAVE NO SPARE PARTS" << std::endl;
                    return false;
                }
            }
            else if(partNum == 3){
                std::cout << "OH NO! ONE OF YOUR TONGUES IS BROKEN!" << std::endl;
                if(party.getTongues() > 0){
                    std::cout << "YOU USE A SPARE TONGUE" << std::endl;
                    party.setTongues(party.getTongues() - 1);
                    return true;
                }
                else{
                    std::cout << "YOU HAVE NO SPARE PARTS" << std::endl;
                    return false;
                }
            }
            else{
                std::cout << "UH UH, something went wrong, check RNG" << std::endl;

            }
            
        }
        else{
            std::cout << "UH OH, SOMETHING WENT WRONG, check RNG" << std::endl;
        }
    }
    return true;
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