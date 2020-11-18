#define MILESTONE_H
#ifdef MILESTONE_H
#include <iostream>

class Milestone{
    public:
        Milestone();
        Milestone(int distance, std::string name);
        int getDistance();
        std::string getName();
        void setDistance(int distance);
        void setName(std::string name);
    private:
        int distance;
        std::string name;
};
#endif