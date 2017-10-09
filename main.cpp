/**
 * Main function demonstrating Concert class.
 *
 * @author Kasey Stowell
 * @date October 2017
 */

#include "Concert.h"

int main(int argc, const char* argv[]) {
    
    // Vector of friends.
    std::vector<std::string> friends1 = {"Alex","Nathan", "Jessica", "Justin"}, friends2 = {"Claudia", "Kayla"},
        friends3 = {"Scott", "Pattie", "Chris", "Elisa"}, friends4 = {"Alex"}, friends5 = {"Max", "Monty", "Baxter"};
    
    // Various concert dates.
    std::tm concertDate1 = Concert::createDate(11,27,2017), concertDate2 = Concert::createDate(5, 13, 2018),
            concertDate3 = Concert::createDate(7, 1, 2018), concertDate4 = Concert::createDate(5, 23, 2019),
            concertDate5 = Concert::createDate(12,25,2019), concertDate6 = Concert::createDate(4,22,2018),
            concertDate7 = Concert::createDate(10, 31, 2017), concertDate8 = Concert::createDate(7, 19, 2019),
            concertDate9 = Concert::createDate(3, 13, 2018);
    
    // Concert objects.
    Concert concert1("Octocat", friends4, 8, concertDate3), concert2("In Sink", friends1, 9, concertDate1), concert3("John Lemon", friends2, 3, concertDate2),
            concert4("Juan Direction", friends3, 1, concertDate3),
            concert5("Seven Degrees Celsius", friends4, 4, concertDate4),
            concert6("Boy Band", friends5, 5, concertDate5), concert7("Beaver Boys", friends1, 10, concertDate6),
            concert8("Party Posse", friends2, 9, concertDate7), concert9("2Gether", friends3, 7, concertDate8),
            concert10("Boyz 4 Now", friends4, 2, concertDate9);
    
    // Vector of Concerts.
    std::vector<Concert> concertList = {concert1, concert2, concert3, concert4, concert5, concert6, concert7,
            concert8, concert9, concert10};
    
    // List Concerts through iteration.
    std::cout << "\n\nNOW LISTING CONCERTS IN NO PARTICULAR ORDER...\n\n";
    for (const auto &i : concertList)
        std::cout << i;
    
    // List Concerts in ascending order by date.
    std::cout << "\n\n\nNOW LISTING CONCERTS IN ORDER OF DATE...\n\n";
    std::sort(concertList.begin(), concertList.end());
    for (const auto &i : concertList)
        std::cout << i;
    
    return 0;
    
}