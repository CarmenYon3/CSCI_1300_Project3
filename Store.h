// Peter Ashmore & Michael Yon

#define STORE_H
#ifdef STORE_H
#include <iostream>
class Store{
    public:
        
        Store();
        Store(int storeNum);

        int getStoreNum();

        double getFoodPrice();
        
        int getOxenYokePrice();

        int getBulletsBoxPrice();

        int getWagonPartsPrice();

        int getMedKitPrice();

    private:

        int storeNum;
        double foodPrice;
        double oxenYokePrice;
        double bulletsBoxPrice;
        double wagonPartsPrice;
        double medKitPrice;
};
#endif