/**
 * Holds information for a concert.
 *
 * @author Kasey Stowell
 * @date October 2017
 */

#include "Concert.h"

/**
 * A new concert is initialized with the name set to "None",
 * the list of friends empty, the value of desire set to one,
 * and the date of the show set to January 1st 2018.
 */
Concert::Concert() {
    concertName = "None";
    friends = {" "};
    desire = 1;
    date.tm_mon = 0;
    date.tm_mday = 1;
    date.tm_year = 118;
}

/**
 * Holds concert information including who will be performing,
 * the list of people you want to take with you (can be empty or arbitrarily full,
 * a value from 1-10 concerning how badly you want to see this show, and the
 * date of the show.
 *
 * @param concertName a string concert name.
 * @param friends a vector of strings listing friend names.
 * @param desire an integer that can be from 1-10.
 * @param date a structure holding a calendar date.
 */
Concert::Concert(std::string concertName, std::vector<std::string> friends, int desire, std::tm date) {
    this->concertName = std::move(concertName);
    this->friends = std::move(friends);
    // Check to make sure that the value for desire is between 1-10.
    if (desire > 10 || desire < 0)
        throw std::invalid_argument("Desire value must be a number from 1-10");
    this->desire = desire;
    this->date = date;
}

/**
 * Overloads the << operator so when a Concert object is passed, the Concert name,
 * friend list, desire rating, and date are printed.
 *
 * @param os an ostream object.
 * @param c a Concert object.
 * @return a string with the following format:
 * ************
 * Concert: Name of Concert
 * Friends: Friend 1. Friend 2. Friend 3.
 * Desire: Desire Value
 * Date: MM-DD-YYYY
 * ************
 */
std::ostream& operator<<(std::ostream &os, const Concert& c) {
    os << "\n\n************\n\nConcert: " << c.concertName << "\nFriends: ";
    // Iterate through vector of friends.
    for (const auto &i : c.friends)
        os << i << ". ";
    os << "\nDesire: " << c.desire << "\nDate: "
       << c.date.tm_mon + 1 << "-" << c.date.tm_mday << "-" << c.date.tm_year + 1900;
    return os;
}

/**
 * Overloads the < operator so that two Concert objects can be compared.
 *
 * @param curr a reference to a Concert object.
 * @param other a reference to a Concert object.
 * @return true if the curr Concert has an earlier date than the other Concert.
 * If curr and other Concert have the same date,
 * then it returns true if curr Concert has a higher desire value than the other Concert.
 */
bool operator<(const Concert &curr, const Concert &other) {
    // Combines year, month, and day into a single comparable int.
    // Example: 2017-10-4 turns into--> 20171004.
    int currVal = (10000 * curr.date.tm_year) + (100 * curr.date.tm_mon) + curr.date.tm_mday;
    int otherVal = (10000 * other.date.tm_year) + (100 * other.date.tm_mon) + other.date.tm_mday;
    // Return true if the current date is *earlier* than the other date.
    if (currVal < otherVal)
        return true;
    // If the dates are the same, return true if the current date has a *higher* desire.
    if (currVal == otherVal)
        if (curr.desire > other.desire)
            return true;
    // Return false otherwise.
    return false;
}

/**
 * Checks if a given date is valid.
 * Leap years are not considered.
 *
 * @param month int representation of a month 1-12.
 * @param day int representation of a day 1-31.
 * @param year int representation of a year 2017-2019 only.
 * @return true if a valid date.
 */
bool Concert::checkDate(int month, int day, int year) {
    if (year < 2017 || year > 2019)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
        return false;
    if (month == 2 && day > 28)
        return false;
    return true;
}

/**
 * Creates a valid date structure for our Concert.
 *
 * @param month int representation of a month 1-12.
 * @param day int representation of a day 1-31.
 * @param year int representation of a year 2017-2019 only.
 * @return valid Concert date structure with month, day, and year instantiated.
 */
struct tm Concert::createDate(int month, int day, int year) {
    // Check if a date is valid.
    if (checkDate(month, day, year)) {
        struct tm validDate{};
        // Date uses 0-11 for months after January.
        validDate.tm_mon = month - 1;
        validDate.tm_mday = day;
        // Date uses years since 1900.
        validDate.tm_year = year - 1900;
        return validDate;
    } else {
        throw std::invalid_argument("Must be a valid date from 2016 thru 2019");
    }
}