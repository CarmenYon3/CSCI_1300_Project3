// Peter Ashmore & Michael Yon

#define TIME_H
#ifdef TIME_H

class Time{
    public:
        Time();
        Time(int day, int month, int year);
        int getDay();
        int getMonth();
        int getYear();
        
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);

        void addDays(int days);
        int getdaysInMonth(int index);
    private:
        static const int NUM_MONTHS = 12;
        int day;
        int month;
        int year;
        int daysInMonth[12];
};
#endif