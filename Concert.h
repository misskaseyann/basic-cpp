/*
 * Holds information for a concert.
 *
 * Kasey Stowell
 * October 2017
 */

#ifndef CONCERTHW_CONCERT_H
#define CONCERTHW_CONCERT_H


#include <string>
#include <vector>

class Concert {
    
    public:
        // Default constructor with no parameters.
        Concert();
        
        // Constructor with parameters.
        Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date);
    
        // Getters
        std::string getConcertName();
        std::vector<std::string> getFriends();
        int getDesire();
        std::tm getDate();
        
        // Setters
        void setConcertName(std::string concertName);
        void setFriends(std::vector<std::string> friends);
        void setDesire(int desire);
        void setDate(std::tm date);
        
    private:
        std::string concertName;
        std::vector<std::string> friends;
        int desire;
        std::tm date;
        
};


#endif //CONCERTHW_CONCERT_H
