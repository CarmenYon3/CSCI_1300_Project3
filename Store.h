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
        
        int getOxenPrice();

        int getBulletsPrice();

        int getWagonPrice();

        int getMedKitPrice();

    private:

        int storeNum;
        double foodPrice;
        int oxenPrice;
        int bulletsPrice;
        int wagonPrice;
        int medKitPrice;
};
#endif