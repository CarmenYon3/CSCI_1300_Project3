#define TIME_H
#ifdef TIME_H

class Time{
    public:
        Time();
        Time(int day, int month, int year, int daysInMonth[]);
        int getDay();
        int getMonth();
        int getYear();
        int addDays();
    private:
        int day;
        int month;
        int year;
        int daysInMonth[];
};
#endif