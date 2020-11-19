// Peter Ashmore & Michael Yon

#define TIME_H
#ifdef TIME_H

class Time{
    public:
        Time();
        Time(int day, int month, int year, int daysInMonth[]);
        int getDay();
        int getMonth();
        int getYear();
        void addDays(int days);
    private:
        static const int NUM_MONTHS = 12;
        int day;
        int month;
        int year;
        int daysInMonth[12];
};
#endif