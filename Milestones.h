// Peter Ashmore & Michael Yon

#define MILESTONES_H
#ifdef MILESTONES_H
#include <iostream>
#include "Milestone.h"

class Milestones{
    public:
        Milestones();
        int readMileStones(std::string fileName);
        int getMilesTraveled();
        void setMilesTraveled(int miles);
        std::string getNextMilestoneName();
        int getNextMilestoneDist();
    private:
        static const int NUM_MILESTONES = 15;
        int milesTraveled;
        Milestone milestones[NUM_MILESTONES];
};
#endif