// Peter Ashmore & Michael Yon

#include <iostream>
#include <iomanip>

#include "Store.h"

/**
 * Default constructor; sets store number to 0
 */

Store::Store(){

    storeNum = 0;
}

/**
 * Paramaterized constructor; sets store number to input
 * @param newStoreNum inputted store number
 */

Store::Store(int newStoreNum){

    storeNum = newStoreNum;
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
 * @return returns oxen price
 */

int Store::getOxenPrice(){

    return oxenPrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns price of bullets
 */

int Store::getBulletsPrice(){

    return bulletsPrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns wagon parts price
 */

int Store::getWagonPrice(){

    return wagonPrice * (1 + (0.25 * storeNum));
}

/**
 * @return returns med kit price
 */

int Store::getMedKitPrice(){

    return medKitPrice * (1 + (0.25 * storeNum));
}



