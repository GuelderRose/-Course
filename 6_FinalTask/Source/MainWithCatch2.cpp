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

#define CATCH_CONFIG_MAIN
#include "C:/Users/Asus/Desktop/catch.hpp"

TEST_CASE("Tests for Date", "[classic]")
{
    Date date(2019, 9, 1);
    REQUIRE(date.GetYear() == 2019);
    REQUIRE(date.GetMonth() == 9);
    REQUIRE(date.GetDay() == 1);
}
