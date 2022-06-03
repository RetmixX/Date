//
// Created by Andrey Neupokoev on 28.05.2022.
//
#include<iostream>
#include "DateTime.h"

namespace DateTime {

	DateTime::DateTime() {}

	DateTime::DateTime(int year, int month, int day)
	{
		if (CheckRangeYear(year) && CheckRangeMonth(month) && CheckRangeDay(day))
		{
			this->year = year;
			this->month = month;
			this->day = day;
			return;
		}

		std::exception("Out of Range!");
	}

	bool DateTime::operator>(const DateTime& dateTime)
	{
		return this->year > dateTime.year || this->month > dateTime.month || this->day > dateTime.day;
	}

	bool DateTime::operator<(const DateTime& dateTime)
	{
		return this->year < dateTime.year || this->month < dateTime.month || this->day < dateTime.day;
	}

	bool DateTime::operator>=(const DateTime& dateTime)
	{
		return this->year >= dateTime.year || this->month >= dateTime.month || this->day >= dateTime.day;
	}

	bool DateTime::operator<=(const DateTime& dateTime)
	{
		return this->year <= dateTime.year || this->month <= dateTime.month || this->day <= dateTime.day;
	}

	bool DateTime::operator==(const DateTime& dateTime)
	{
		return this->year == dateTime.year && this->month == dateTime.month && this->day == dateTime.day;
	}

	std::string DateTime::DateToString(char culture)
	{
		switch (culture)
		{
		case 'd':
		{
			return std::to_string(DateTime::day) + "/" + std::to_string(DateTime::month) + "/" + std::to_string(DateTime::year);
			break;
		}

		case 'D':
		{
			return FindMonth(DateTime::month) + " " + std::to_string(DateTime::day) + ", " + std::to_string(DateTime::year);
			break;
		}

		case 'm':
		{
			return FindMonth(DateTime::month) + " " + std::to_string(DateTime::day);
			break;
		}

		case 'r':
		{
			return std::to_string(DateTime::day) + " " + FindMonth(DateTime::day) + std::to_string(DateTime::year);
			break;
		}
		}
	}

	std::ostream& operator<<(std::ostream& os, const DateTime& dateTime)
	{
		return os << dateTime.year << "." << dateTime.month << "." << dateTime.day;
	}

	std::ifstream& operator>>(std::ifstream& ifs, DateTime& dateTime)
	{
		std::cin >> dateTime.year >> dateTime.month >> dateTime.day;
		return ifs;
	}

	bool DateTime::CheckRangeYear(int year)
	{
		return year >= 1 && year <= 9999;
	}

	bool DateTime::CheckRangeMonth(int month)
	{
		return month > 1 && month <= 12;
	}

	bool DateTime::CheckRangeDay(int day)
	{
		return day >= 1 && day <= 31;
	}

	std::string DateTime::FindMonth(int m)
	{
		std::string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		for (int i = 0; i < 12; i++)
		{
			if ((m - 1) == i)
			{
				return month[i];
			}
		}
	}

}// DateTime