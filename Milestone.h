#define MILESTONE_H
#ifdef MILESTONE_H
#include <iostream>

class Milestone{
    public:
        Milestone();
        int readMileStones(std::string fileName);
        int getMilesTraveled();
        void setMilesTraveled(int miles);
        std::string getNextMilestoneName();
        int getNextMilestoneDist();
    private:
        static const int NUM_MILESTONES = 15;
        int milesTraveled;
        int milestoneDist[NUM_MILESTONES];
        std::string milestoneName[NUM_MILESTONES];
};
#endif