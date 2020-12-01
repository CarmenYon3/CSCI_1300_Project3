// Peter Ashmore & Michael Yon

#include <iostream>
#include <iomanip>
#include <string>
#include "fstream"
#include "Time.h"
#include "Party.h"
#include "Store.h"
#include "Milestones.h"
#include <vector>
#include <cstdlib>
#include <cmath>


//put up here so its accessable
bool puzzle();
/**
 * Takes a minimum and maximum value and returns a random number within that range
 * @param rand_min minimum value of random number
 * @param rand_max maximum value of random number
 * @return the number generated 
*/
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
            std::cout << "RAIDERS AHEAD! THEY LOOK HOSTILE!" << std::endl;
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
        
        // Main store menu where the player chooses which items to buy
        // Loops until player exits
        std::cout << "============================================" << std::endl;
        std::cout << "               General Store                " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "1. Oxen                           $" << oxenBill << std::endl;
        std::cout << "2. Food                           $" << foodBill << std::endl;
        std::cout << "3. Bullets                        $" << bulletsBill << std::endl;
        std::cout << "4. Miscellaneous Supplies         $" << miscSuppliesBill << std::endl;
        std::cout << "5. Exit and purchase" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "                      Total bill: $" << totalBill << std::endl;
        std::cout << std::endl;
        std::cout << "Amount you have: $" << party.getMoney() << std::endl;
        std::cout << std::endl;
        std::cout << "Which item would you like to buy?" << std::endl;
        std::cin >> choice;

        if (choice == 1){
            
            while (true){  
                
                // Menu for buying oxen, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "There are 2 oxen in a yoke;" << std::endl;
                std::cout << "Each yoke costs $" << store.getOxenYokePrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many yoke do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getOxenYokePrice() + totalBill) <= party.getMoney()){

                    oxenBill = num * store.getOxenYokePrice();
                    party.setOxen(party.getOxen() + (num * 2));
                    
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }  
            }
        }

        else if (choice == 2){
            
            while(true){
                
                // Menu for buying food, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each pound of food costs $" << store.getFoodPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many pounds of food do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getFoodPrice() + totalBill) <= party.getMoney()){

                    foodBill = num * store.getFoodPrice();
                    party.setFood(party.getFood() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }
        }

        else if (choice == 3){

            while (true){

                // Menu for buying bullets, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "There are 20 bullets in a box;" << std::endl;
                std::cout << "Each box costs $" << store.getBulletsBoxPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many boxes do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getBulletsBoxPrice() + totalBill) <= party.getMoney()){

                    bulletsBill = num * store.getBulletsBoxPrice();
                    party.setBullets(party.getBullets() + (num * 20));
                    
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }  
            }
        }

        else if (choice == 4){
            
            while (true){

                // Menu for buying wagon wheels, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each wagon wheel costs $" << store.getWagonPartsPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many wagon wheels do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getWagonPartsPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill = num * store.getWagonPartsPrice();
                    party.setWheels(party.getWheels() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            } 

            while (true){

                // Menu for buying wagon axles, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each wagon axle costs $" << store.getWagonPartsPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many wagon axles do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getWagonPartsPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill += num * store.getWagonPartsPrice();
                    party.setAxles(party.getAxles() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }

            while (true){

                // Menu for buying wagon tongues, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each wagon tongue costs $" << store.getWagonPartsPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many wagon tongues do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getWagonPartsPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill += num * store.getWagonPartsPrice();
                    party.setTongues(party.getTongues() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }

            while (true){

                // Menu for buying medkits, loops until player can afford the purchase
                std::cout << "============================================" << std::endl;
                std::cout << "               General Store                " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each medical aid kit costs $" << store.getMedKitPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many medical aid kits do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getMedKitPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill += num * store.getWagonPartsPrice();
                    party.setMedKits(party.getMedKits() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }
                
        }
        else if (choice == 5){

            // Makes purchase final and exits the store
            std::cout << "Total bill: $" << totalBill << std::endl;
            std::cout << "Thank you for shopping! Good luck!" << std::endl;
            party.setMoney(party.getMoney() - totalBill);
            break;
        }
        else{

            // Prints if input number isn't one of the options
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        totalBill = oxenBill + foodBill + bulletsBill + miscSuppliesBill;
    }  
}

/**
 * Called when the player enters the store in Independence 
 * presents a menu and racks up a bill as the player selects items
 * upon exiting, the bill is subrtraced from the party stats
 * @param party party taken as input (reference)
 * @param store store taken as input (reference)
 */
void initialShop(Party &party, Store &store){

    double oxenBill = 0.00;
    double foodBill = 0.00;
    double bulletsBill = 0.00;
    double miscSuppliesBill = 0.00;
    double totalBill = oxenBill + foodBill + bulletsBill + miscSuppliesBill;
    int choice = 0;

    // Describes all items in the store and provides advice on what to buy
    std::cout << "Before you start your journey, you need to stock up on supplies" << std::endl;
    std::cout << "You have saved $1600 to spend on the following items in the general store: " << std::endl;
    std::cout << "=========================================================================================" << std::endl;
    std::cout << "Oxen:" << std::endl;
    std::cout << "You can spend $100-$200 on your team." << std::endl;
    std::cout << "The more you spend, the faster you'll go because you'll have the better animals." << std::endl;
    std::cout << std::endl;
    std::cout << "Food:" << std::endl;
    std::cout << "The more you have, the less chance there is of getting sick." << std::endl;
    std::cout << std::endl;
    std::cout << "Ammunition:" << std::endl;
    std::cout << "You will need bullets for attacks by animals and bandits and for hunting food." << std::endl;
    std::cout << std::endl;
    std::cout << "Miscellaneous:" << std::endl;
    std::cout << "This includes medicine and other things you will need for sickness and emergency repairs." << std::endl;
    std::cout << "=========================================================================================" << std::endl;
    std::cout << "You can spend all your money before you start your trip. " << std::endl; 
    std::cout << "Alternatively, you can save some of your cash to spend at forts along the way when you run low on supplies." << std::endl;
    std::cout << "However, items cost more at the forts." << std::endl;
    std::cout << "You can also go hunting along the way to get more food." << std::endl;

    while (true){
        
        // Menu for Independence store, player selects item to buy
        std::cout << "============================================" << std::endl;
        std::cout << "       Independence, MO General Store       " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "1. Oxen                           $" << oxenBill << std::endl;
        std::cout << "2. Food                           $" << foodBill << std::endl;
        std::cout << "3. Bullets                        $" << bulletsBill << std::endl;
        std::cout << "4. Miscellaneous Supplies         $" << miscSuppliesBill << std::endl;
        std::cout << "5. Exit and purchase" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "                      Total bill: $" << totalBill << std::endl;
        std::cout << std::endl;
        std::cout << "Amount you have: $" << party.getMoney() << std::endl;
        std::cout << std::endl;
        std::cout << "Which item would you like to buy?" << std::endl;
        std::cin >> choice;

        if (choice == 1){
            
            while (true){

                // Menu for buying oxen, loops until player can afford purchase and chooses correct number of yoke
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "You must buy 3-5 yokes before leaving Independence." << std::endl;
                std::cout << "There are 2 oxen in a yoke" << std::endl;
                std::cout << "Each yoke costs $" << store.getOxenYokePrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many yoke do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getOxenYokePrice() + totalBill) <= party.getMoney() && num >= 3 && num <= 5){

                    oxenBill = num * store.getOxenYokePrice();
                    party.setOxen(party.getOxen() + (num * 2));
                    
                    break;
                }
                else if((num < 3 || num > 5 && num * store.getOxenYokePrice() + totalBill) <= party.getMoney()){

                    std::cout << "You must buy 3-5 yokes before leaving Independence. Please enter a different number." << std::endl;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }  
            }
        }

        else if (choice == 2){
            
            while(true){

                // Menu for buying food, loops until player can afford purchase
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "It is recommended that you purchase at least 200 lbs. of food before departing." << std::endl;
                std::cout << "Each pound of food costs $" << store.getFoodPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many pounds of food do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getFoodPrice() + totalBill) <= party.getMoney()){

                    foodBill = num * store.getFoodPrice();
                    party.setFood(party.getFood() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }
        }

        else if (choice == 3){

            while (true){

                // Menu for buying bullets, loops until player can afford purchase
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "There are 20 bullets in a box;" << std::endl;
                std::cout << "Each box costs $" << store.getBulletsBoxPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many boxes do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getBulletsBoxPrice() + totalBill) <= party.getMoney()){

                    bulletsBill = num * store.getBulletsBoxPrice();
                    party.setBullets(party.getBullets() + (num * 20));
                    
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }  
            }
        }

        else if (choice == 4){
            
            while (true){

                // Menu for buying wagon wheels, loops until player can afford purchase
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each wagon wheel costs $" << store.getWagonPartsPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many wagon wheels do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getWagonPartsPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill = num * store.getWagonPartsPrice();
                    party.setWheels(party.getWheels() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            } 

            while (true){

                // Menu for buying wagon axles, loops until player can afford purchase
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each wagon axle costs $" << store.getWagonPartsPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many wagon axles do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getWagonPartsPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill += num * store.getWagonPartsPrice();
                    party.setAxles(party.getAxles() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }

            while (true){

                // Menu for buying bullets, loops until player can afford purchase
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each wagon tongue costs $" << store.getWagonPartsPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many wagon tongues do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getWagonPartsPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill += num * store.getWagonPartsPrice();
                    party.setTongues(party.getTongues() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }

            while (true){

                // Menu for buying medkits, loops until player can afford purchase
                std::cout << "============================================" << std::endl;
                std::cout << "       Independence, MO General Store       " << std::endl;
                std::cout << "============================================" << std::endl;
                std::cout << "Each medical aid kit costs $" << store.getMedKitPrice() << std::endl;
                std::cout << std::endl;
                std::cout << "How many medical aid kits do you want to purchase?" << std::endl;
                int num = 0;
                std::cin >> num;
                if ((num * store.getMedKitPrice() + totalBill) <= party.getMoney()){

                    miscSuppliesBill += num * store.getWagonPartsPrice();
                    party.setMedKits(party.getMedKits() + num);
                        
                    break;
                }
                else{

                    std::cout << "You do not have enough money for this purchase" << std::endl;
                    std::cout << "Please enter a different amount" << std::endl;
                    continue;
                }
            }
                
        }
        else if (choice == 5){

            // Exits player from the store and finalizes purchase
            std::cout << "Total bill: $" << totalBill << std::endl;
            std::cout << "Thank you for shopping! Good luck!" << std::endl;
            party.setMoney(party.getMoney() - totalBill);
            break;
        }
        else{

            std::cout << "Invalid input" << std::endl;
            continue;
        }

        totalBill = oxenBill + foodBill + bulletsBill + miscSuppliesBill;
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
void continueOn(Party &party, Time &time,Milestones &milestones,Store &store){
    time.addDays(14);
    int distance = randomNumberGenerator(70,71); //generates a random number between 70 and 140 (distance traveled)
    int foodUsed = 0;

    if(distance > milestones.getNextMilestoneDist()){
        std::string milestoneArrivedAt = milestones.getNextMilestoneName();        
        for(int i = 0; i < 14; i++){
                foodUsed += 3; //food eaten by player

                for(int j = 0; j < 4; j++){
                    if(party.getPartyLifeAt(j) == true){
                        foodUsed += 3;//food eaten by each party member
                    }
                }
            }
        
            
            milestones.setMilesTraveled(milestones.getMilesTraveled() + milestones.getNextMilestoneDist());//adds the distance to the total miles traveled
            party.setFood(party.getFood() - foodUsed);

        if(milestoneArrivedAt.find("Fort") != std::string::npos){//if the milestone is a fort
            std::cout << "YOU WERE PREPARED TO TRAVEL " << distance << " MILES" << std::endl;
            std::cout <<  "BUT YOU ARRIVED AT " << std::endl;
            std::cout << milestoneArrivedAt << std::endl; 
            std::cout << ". WHAT DO YOU WANT TO DO:" << std::endl;
                     

            while(true){
                std::cout << "(1) REST, (2) CONTINUE, (3) SHOP" << std::endl;

                int choice;
                std::cin >> choice;
                if(choice == 1){
                    rest(party,time);
                    
                }
                else if(choice == 2){
                    store.setStoreNum(store.getStoreNum() + 1);
                    break;
                }
                else if(choice == 3){
                    shop(party,store);
                    break;
                }
                else{
                    std::cout << "Invalid input, try again" << std::endl;
                    continue;
                }
            }

        }
        else{
            std::cout << "YOU WERE PREPARED TO TRAVEL " << distance << " MILES" << std::endl;
            std::cout <<  "BUT YOU ARRIVED AT " << std::endl;
            std::cout << milestoneArrivedAt << std::endl; 
            std::cout << "WHAT DO YOU WANT TO DO:" << std::endl;

            while(true){
                std::cout << "(1) REST, (2) CONTINUE" << std::endl;
                int choice;
                std::cin >> choice;
                if(choice == 1){
                    rest(party,time);
                    continue;
                }
                else if(choice == 2){
                    break;
                }
                else{
                    std::cout << "Invalid input, try again" << std::endl;
                }
            }
        }
    }
    else{
        for(int i = 0; i < 14; i++){
            foodUsed += 3; //food eaten by player

            for(int j = 0; j < 4; j++){
                if(party.getPartyLifeAt(j) == true){
                    foodUsed += 3;//food eaten by each party member
                }
            }
        }
    
    
        milestones.setMilesTraveled(milestones.getMilesTraveled() + distance);//adds the distance to the total miles traveled
        party.setFood(party.getFood() - foodUsed);
    }
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

                        party.setMedKits(party.getMedKits() - 1);

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
                        party.setMedKits(party.getMedKits() - 1);

                        if(randomNumberGenerator(0,2) == 0){//50% change
                            std::cout << party.getPartyMembersAt(choice) << " DIES OF " << disease << std::endl;
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
                                    std::cout << party.getPartyMembersAt(choice) << " DIES OF " << disease << std::endl;
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
        int temp1 = randomNumberGenerator(1,10);
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
 * Writes the score at the end of the game to a high score list
 * pass the file into a vector, sorts vector using bubble sort, rewrites file using new vector
 * file being written to will contain previous runs high scores
 * @param party party taken as input (reference)
 * @param time store taken as input (reference)
 * @param milestones milestones object taken as input (reference)
 */
void writeResults(Party &party, Time &time, Milestones &milestones){

    std::ifstream inFile;
    std::ofstream outFile;

    std::vector<int> scores;
    std::vector<std::string> names;

    inFile.open("results.txt");

    if(inFile.fail()){
        std::cout << "something went wrong" << std::endl;
    }
    else{
        std::string line = "";
        while(std::getline(inFile,line)){
            names.push_back(line);
            std::getline(inFile,line);
            scores.push_back(stoi(line));
        }
        names.push_back(party.getName());
        scores.push_back(milestones.getMilesTraveled());

        bubbleSortHighScore(scores,names);

        outFile.open("results.txt",  std::ofstream::out | std::ofstream::trunc );

        for(unsigned int i = 0; i < scores.size(); i++){
            outFile << names[i] << "\n";
            outFile << scores[i] << "\n";
        }
    }

}

/**
 * Allows the player to set the initial date, or keep the normal initial date
 * modifies time accordingly
 * @param time time taken as input
 */
void setStartDate(Time &time_){
        time_.setDay(1);
        time_.setMonth(3);
        time_.setYear(1847);
        while(true){
        std::cout << "Your departure date currently is: " << time_.getYear() << "-" << time_.getMonth() << "-" << time_.getDay() << ". Would you like to change it?" << std::endl;
        std::cout << "Y / N" << std::endl;

        char choice;
        std::cin >> choice;

        if(choice == 'N' || choice == 'n'){//default date
            break;
        }
        else if(choice == 'Y' || choice == 'y'){
            std::cout << "Enter a date between 03/01/1847 and 05/01/1847" << std::endl;
            while(true){

                std::cout << "month: ";
                int monthIn;
                std::cin >> monthIn;


                if(monthIn > 5 || monthIn < 3){
                    std::cout << "Invalid input, try again" << std::endl;
                    continue;
                }
                else{
                    time_.setMonth(monthIn);
                    std::cout << "day: ";
                    int dayIn;
                    std::cin >> dayIn;
                    if(dayIn < 0 || dayIn > time_.getdaysInMonth(monthIn-1)){
                        std::cout << "Invalid input, try again" << std::endl;
                        continue;
                    }
                    else{
                        if(monthIn == 5){
                            std::cout << "The only day within may is the 1st setting accordingly" << std::endl;
                            time_.setDay(1);
                            time_.setYear(1847);
                            break;
                        }
                        time_.setDay(dayIn);
                        time_.setYear(1847);
                        break;
                    }
                }
            }
        }
        else{
            std::cout << "Invalid input, try again" << std::endl;
            continue;
        }


    }
}

int main(){
    //enter name
    std::cout << "What is your name?:" << std::endl;
    std::string playerName;
    std::getline(std::cin, playerName);


    //enter party members name
    std::cout << "Enter the names of your companions" << std::endl;
    std::string partyMemberNames[4];
    std::cout << "1.";
    std::getline(std::cin, partyMemberNames[0]);
    std::cout << "2.";
    std::getline(std::cin, partyMemberNames[1]);
    std::cout << "3.";
    std::getline(std::cin, partyMemberNames[2]);
    std::cout << "4.";
    std::getline(std::cin, partyMemberNames[3]);


    //construct party object
    Party party = Party(playerName,partyMemberNames);
    party.setMoney(1600);


    std::cout << "You are starting at mile: 0." << std::endl;
    //first store
    std::cout << "There are 2040 that you must travel to reach your destination." << std::endl;
    std::cout << "Before the start of your trip, you can visit the store and buy supplies: " << std::endl;
    std::cout << "food, oxen, bullets and wagon parts. Would you like to visit the store? Y / N " << std::endl;

    Store store = Store();

    while(true){
        char choice;
        std::cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            initialShop(party,store);
            break;
        }
        else if(choice == 'n' || choice == 'N'){
            break;
        }
        else{
            std::cout << "Invalid input, try again" << std::endl;
            continue;
        }
    }


    //ask for start date
    Milestones milestones = Milestones();
    milestones.readMileStones("milestones.txt");
    

    Time time = Time();

    setStartDate(time);

    //begin turn loop
    
    while(true){
        //display stats
        std::cout <<"\n" << time.getYear() << "-" << time.getMonth() << "-" << time.getDay() << std::endl;
        std::cout << "You have traveled " << milestones.getMilesTraveled() << " miles." << std::endl;
        std::cout << "Next milestone is: " <<  milestones.getNextMilestoneName() << std::endl;
        std::cout << "It is " << milestones.getNextMilestoneDist() << " miles away." << std::endl;
        std::cout << "Food: " << party.getFood() << std::endl;
        std::cout << "Money: " << party.getMoney() << std::endl;
        std::cout << "Oxen: " << party.getOxen() << std::endl;
        std::cout << "Bullets: " << party.getBullets() << std::endl;
        std::cout << "Wagon Parts: " << party.getAxles() + party.getTongues() + party.getWheels() << std::endl;
        std::cout << "Medkits: " << party.getMedKits() << std::endl;
        std::cout << "What would you like to do?: 1.  Rest; 2. Continue; 3. Hunt; 4. Quit \n" << std::endl;

        //checks for game over cases
        while(true){
            if(party.getOxen() <= 0){
                std::cout << "You ran out of oxen. Game Over" << std::endl;
                writeResults(party,time,milestones);
                return 0;
            }
            if(party.getFood() <= 0){
                std::cout << "You ran out of food. Game Over" << std::endl;
                writeResults(party,time,milestones);
                return 0;
            }
            
            //player makes choice
            int choice; 
            std::cin >> choice;
            if(choice == 1){
                rest(party,time);
                break;
            }
            else if(choice == 2){
                continueOn(party,time,milestones,store);
                break;
            }
            else if(choice == 3){
                hunt(party,time);
                break;
            }
            else if(choice == 4){
                break;
            }

        }
        //misfortune and raider attacks
        raiderAttack(party,milestones);
        std::cout << "\n";
        if(misfortune(party,time) == false){
            std::cout << "Game Over" << std::endl;
            writeResults(party,time,milestones);
            return 0;
        }
        std::cout << "\n";
        if(milestones.getMilesTraveled() >= 2040){
            std::cout << "You arrived at Oregon City. Congradulations, you win!" << std::endl;
            writeResults(party,time,milestones);
            return 0;
        }
    }
}