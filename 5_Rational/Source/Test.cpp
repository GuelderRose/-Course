#include "Header.h"
#define CATCH_CONFIG_MAIN
#include "C:/Users/Asus/Desktop/catch.hpp" 

TEST_CASE("Tests for TestParse", "[classic]")
{
    REQUIRE(TestParse("{3/0}") == false);
    REQUIRE(TestParse("{3/1}") == true);
    REQUIRE(TestParse("{0/1}") == true);
    REQUIRE(TestParse("{3,1}") == false);
    REQUIRE(TestParse("r") == false);
}
TEST_CASE("Tests for operators", "[classic]")
{
    Rational z(1, 2);
    Rational f(1, 2);
    Rational sum(1, 1);
    Rational s = z + f;
    CHECK((sum == s) == true);
    z = 3;
    f = { 2, 1 };
    Rational res(3, 2);
    Rational r = z / f;
    CHECK(((z / f) == res)==true);
}
/*
int main() {
    using namespace std;
    Rational z;
    z += Rational(8);
    cout << z << endl;
    TestParse("{3/4}");
    TestParse("{3,4}");
    TestParse("{3/0}");
    cout << endl;
    Rational x(20, 15);
    cout << x << endl;
    cout << x + z << endl;
    system("pause");
    return(0);
}
*/