#define MILESTONE_H
#ifdef MILESTONE_H
#include <iostream>

class Store{
    public:
        int readMileStones();
    private:
        static const int NUM_MILESTONES = 15;
        int milesTraveled;
        int milestoneDist[NUM_MILESTONES];
        int mileStoneName[NUM_MILESTONES];
};
#endif