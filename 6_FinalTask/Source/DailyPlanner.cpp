#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <exception>
#include <sstream>
#include"DailyPlanner.h"

int Date::GetYear() const {
    return this->year;
}
int Date::GetMonth() const {
    return this->month;
}
int Date::GetDay() const {
    return this->day;
}
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    else {
        if (lhs.GetMonth() != rhs.GetMonth()) {
            return lhs.GetMonth() < rhs.GetMonth();
        }
        else {
            return lhs.GetDay() < rhs.GetDay();
        }
    }
}
void Database::AddEvent(const Date& date, const std::string& event) {
    if (DailyPlanner.count(date) > 0) {
        if (count(DailyPlanner[date].cbegin(),
            DailyPlanner[date].cend(), event) == 0) {
            DailyPlanner[date].insert(event);
        }

    }
    else {
        DailyPlanner[date].insert(event);
    }
}
bool Database::DeleteEvent(const Date& date, const std::string& event) {
    if (DailyPlanner.count(date) > 0 &&
        DailyPlanner[date].count(event) > 0) {
        DailyPlanner[date].erase(event);
        return true;
    }
    else {
        return false;
    }
}
int  Database::DeleteDate(const Date& date) {
    if (DailyPlanner.count(date) > 0) {
        int number_of_events = DailyPlanner[date].size();
        DailyPlanner[date].clear();
        return number_of_events;
    }
    else {
        return 0;
    }
}
void Database::Find(const Date& date) const {
    if (DailyPlanner.count(date) > 0) {
        for (const auto& item : DailyPlanner.at(date)) {
            std::cout << item << std::endl;
        }
    }
}
void Database::Print() const {
    for (const auto& group_of_events : DailyPlanner) {
        for (const auto& event : group_of_events.second) {
            std::cout << std::setfill('0')
                << std::setw(4) << group_of_events.first.GetYear() 
                << "-" << std::setfill('0')
                << std::setw(2) << group_of_events.first.GetMonth()
                << "-" << std::setfill('0')
                << std::setw(2) << group_of_events.first.GetDay() 
                << " " << event << std::endl;
        }
    }
}
void EnsureNextSymbolAndSkip(std::stringstream& str) {
    if (str.peek() != '-') {
        std::stringstream message;
        std::string wrong_date = str.str();
        message << "Wrong date format: " << wrong_date;
        throw std::runtime_error(message.str());
    }
    str.ignore(1);
}
Date DateParse(const std::string& date) {
    std::stringstream str(date);
    int year = 0, month = 0, day = 0;
    str >> year;
    EnsureNextSymbolAndSkip(str);
    str >> month;
    EnsureNextSymbolAndSkip(str);
    if (month < 1 || month > 12) {
        std::stringstream message;
        std::string wrong_month = str.str();
        message << "Month value is invalid: " << wrong_month;
        throw std::runtime_error(message.str());
    }
    str >> day;
    if (day < 1 || day > 31) {
        std::stringstream message;
        std::string wrong_day = str.str();
        message << "Day value is invalid: " << wrong_day;
        throw std::runtime_error(message.str());
    }
    return Date(year, month, day);
}
void CallAddEvent(Database& db, std::stringstream& input) {
    std::string date, event;
    input >> date >> event;
    db.AddEvent(DateParse(date), event);
}
void CallDeleteEventOrData(Database& db, std::stringstream& input) {
    std::string date, event;
    input >> date;
    if (!input.eof()) {
        input >> event;
    }
    if (event == "") {
        int number_of_deleted_events = db.DeleteDate(DateParse(date));
        std::cout << "Deleted " << number_of_deleted_events 
            << " events" << std::endl;
    }
    else {
        bool event_deleting = db.DeleteEvent(DateParse(date), event);
        if (event_deleting) {
            std::cout << "Deleted successfully" << std::endl;
        }
        else {
            std::cout << "Event not found" << std::endl;
        }
    }
}
void CallFind(Database& db, std::stringstream& input) {
    std::string date;
    input >> date;
    db.Find(DateParse(date));
}
