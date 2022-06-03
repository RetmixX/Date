#pragma once
#include <string>

namespace DateTime
{

    class DateTime {
    public:
        int day;
        int month;
        int year;

    public:
        DateTime();
        DateTime(int year, int mouth, int day);


        bool operator>(const DateTime& dateTime);
        bool operator<(const DateTime& dateTime);
        bool operator>=(const DateTime& dateTime);
        bool operator<=(const DateTime& dateTime);
        bool operator==(const DateTime& dateTime);


        friend std::ostream& operator<<(std::ostream& os, const DateTime& dateTime);
        friend std::ifstream& operator>>(std::ifstream& ifs, DateTime& dateTime);


        std::string DateToString(char culture);

    private:
        bool CheckRangeYear(int year);
        bool CheckRangeMonth(int month);
        bool CheckRangeDay(int day);
        std::string FindMonth(int m);
    };

} // DateTime
