// Peter Ashmore & Michael Yon

#include <iostream>
#include <iomanip>

#include "Store.h"

/**
 * Default constructor; sets store number to 0
 */

Store::Store(){

    storeNum = 0;
    
    foodPrice = 0.50;
    oxenYokePrice = 40.00;
    bulletsBoxPrice = 2.00;
    wagonPartsPrice = 20.00;
    medKitPrice = 25.00;

}

/**
 * Paramaterized constructor; sets store number to input
 * @param newStoreNum inputted store number
 */

Store::Store(int newStoreNum){

    storeNum = newStoreNum;

    foodPrice = 0.50;
    oxenYokePrice = 40.00;
    bulletsBoxPrice = 2.00;
    wagonPartsPrice = 20.00;
    medKitPrice = 25.00;
    
}

/**
 * @return returns store number
 */

int Store::getStoreNum(){

    return storeNum;
}

/**
 * @return returns food price
 */

double Store::getFoodPrice(){

    return foodPrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns oxen yoke price
 */

int Store::getOxenYokePrice(){

    return oxenYokePrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns price of bullets box
 */

int Store::getBulletsBoxPrice(){

    return bulletsBoxPrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns wagon parts price
 */

int Store::getWagonPartsPrice(){

    return wagonPartsPrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns med kit price
 */

int Store::getMedKitPrice(){

    return medKitPrice * (1 + (0.25 * storeNum));
}


void Store::setStoreNum(int index){
    storeNum = index;
}

