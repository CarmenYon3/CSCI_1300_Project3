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

Time::Time(int day, int month, int year, int daysInMonth[]){
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
    return year;
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

}