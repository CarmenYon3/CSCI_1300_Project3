// Peter Ashmore & Michael Yon

#define PARTY_H
#ifdef PARTY_H
#include <iostream>
class Party{
    public:
        Party();
        Party(std::string name, std::string partyMembers[4]);

        int getOxen();
        void setOxen(int oxen);

        int getFood();
        void setFood(int food);

        int getBullets();
        void setBullets(int bullets);

        int getWheels();
        void setWheels(int wheels);

        int getAxles();
        void setAxles(int axles);

        int getTongues();
        void setTongues(int tongues);

        double getMoney();
        void setMoney(double money);

        int getMedKits();
        void setMedKits(int medKits);

        bool getPartyLifeAt(int index);
        void setPartyLifeAt(int index, bool value);

        std::string getPartyMembersAt(int index);

        std::string getName();
        
    private:
        int oxen;
        int food;
        int bullets;
        int wheels;
        int axles;
        int tongues;
        double money;
        int medKits;
        std::string partyMembers[4];
        std::string name;
        bool partyLife[4];
};
#endif