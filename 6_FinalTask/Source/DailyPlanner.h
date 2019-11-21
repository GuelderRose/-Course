#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <exception>
#include <sstream>
class Date {
public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
    Date() {}
    Date(const int year, const int month, const int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

private:
    int year{ 0 };
    int month{ 0 };
    int day{ 0 };
};
class Database {
public:
    void AddEvent(const Date& date, const std::string& event);
    bool DeleteEvent(const Date& date, const std::string& event);
    int  DeleteDate(const Date& date);
    void Find(const Date& date) const;
    void Print() const;

private:
    std::map<Date, std::set<std::string>> DailyPlanner;
};
void CallAddEvent(Database& db, std::stringstream& input);
void CallDeleteEventOrData(Database& db, std::stringstream& input);
void CallFind(Database& db, std::stringstream& input);
