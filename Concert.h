/**
 * Holds information for a concert.
 *
 * @author Kasey Stowell
 * @date October 2017
 */

#ifndef CONCERTHW_CONCERT_H
#define CONCERTHW_CONCERT_H

#include <string>
#include <vector>
#include <iostream>
#include <ctime>

class Concert {
    
    public:
        /// Default constructor with no parameters.
        Concert();
        
        ///  Constructor with parameters.
        Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date);
        
        /// Overload the < operator.
        friend bool operator<(const Concert& curr, const Concert& other);
        
        /// Overload the << operator.
        friend std::ostream& operator<<(std::ostream& os, const Concert& c);
        
        /// Create structure of date.
        static struct tm createDate(int month, int day, int year);
        
    private:
        std::string concertName;
        std::vector<std::string> friends;
        int desire;
        std::tm date;
        
        /// Checks if a date is valid.
        static bool checkDate(int month, int day, int year);
        
};


#endif //CONCERTHW_CONCERT_H
