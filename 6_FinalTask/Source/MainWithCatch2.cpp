#include"DailyPlanner.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Tests for Date", "[classic]")
{
    Date date(2019, 9, 1);
    REQUIRE(date.GetYear() == 2019);
    REQUIRE(date.GetMonth() == 9);
    REQUIRE(date.GetDay() == 1);
}
TEST_CASE("DeleteEvent", "[classic]")
{
    Date date(2019, 9, 1);
    std::string event = "event1";
    Database db;
    db.AddEvent(date, event);
    REQUIRE(db.DeleteEvent(date,event) == true);
    REQUIRE(db.DeleteEvent(date,event) == false);
}
TEST_CASE("DeleteDate", "[classic]")
{
    Date date1(2019, 9, 1);
    std::string event1 = "event1";
    std::string event2 = "event2";
    Database db;
    db.AddEvent(date1, event1);
    db.AddEvent(date1, event2);
    REQUIRE(db.DeleteDate(date1) == 2);
}
TEST_CASE("Find and AddEvent", "[classic]")
{
    Date date1(2019, 9, 1);
    std::string event1 = "event1";
    std::string event2 = "event2";
    Database db;
    db.AddEvent(date1, event1);
    db.AddEvent(date1, event2);
    std::ostringstream strm; 
    std::cout.rdbuf(strm.rdbuf());
    db.Find(date1);
    std::string str = strm.str();
    REQUIRE(str == "event1\nevent2\n");
}
