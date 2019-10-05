#include "Rational.h"

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

