// Peter Ashmore & Michael Yon

#include "Time.h"
#include <iostream>
/**
 * default constructor for time class
 */
Time::Time(){
    day = 0;
    month = 0;
    year = 0;
    daysInMonth[0] = 31;
    daysInMonth[1] = 28;
    daysInMonth[2] = 31;
    daysInMonth[3] = 30;
    daysInMonth[4] = 31;
    daysInMonth[5] = 30;
    daysInMonth[6] = 31;
    daysInMonth[7] = 31;
    daysInMonth[8] = 30;
    daysInMonth[9] = 31;
    daysInMonth[10] = 30;
    daysInMonth[11] = 31;
}
/**
 * @param day day to start at
 * @param month month to start at year -1
 * @param year year to start at
 */
Time::Time(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
    this->daysInMonth[0] = 31;
    this->daysInMonth[1] = 28;
    this->daysInMonth[2] = 31;
    this->daysInMonth[3] = 30;
    this->daysInMonth[4] = 31;
    this->daysInMonth[5] = 30;
    this->daysInMonth[6] = 31;
    this->daysInMonth[7] = 31;
    this->daysInMonth[8] = 30;
    this->daysInMonth[9] = 31;
    this->daysInMonth[10] = 30;
    this->daysInMonth[11] = 31;
}

/**
 * @return day of the month
 */
int Time::getDay(){
    return day;
}

/**
 * @return month of the year
 */
int Time::getMonth(){
    return month;
}
/**
 * @return the year
 */
int Time::getYear(){
    return year;
}
/**
 * Takes a number of days as input, adjusts the time accordingly
 * @param days days to be added to the date
 */
void Time::addDays(int days){
    if((days + day) > daysInMonth[month]){
        if(month == 11){
            day = (days + day) % daysInMonth[month];
            month = 0;
            year++;
        }
        else{
            day = (days + day) % daysInMonth[month];
            month++;
        }
    }
    else{
        day += days;
    }
}

int Time::getdaysInMonth(int index){
    return daysInMonth[index];
}

void Time::setDay(int day){
    this->day = day;
}
void Time::setMonth(int month){
    this->month = month;
}
void Time::setYear(int year){
    this->year = year;
}

/* tester for add days */
// int main(){
//     Time test  = Time(29,11,1894);
//     std::cout << test.getDay() << " " << test.getMonth() << " " << test.getYear() << std::endl;
//     test.addDays(12);
//     std::cout << test.getDay() << " " << test.getMonth() << " " << test.getYear() << std::endl;
//     return 0;
// }