#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include "Rational.h"

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}
inline  std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}
Rational::Rational(const int numerator)
    :numerator(numerator)
    , denominator(1)
{}
Rational::Rational(const int numerator, const int denominator)
    : numerator(numerator) {
    if (denominator != 0) {
        this->denominator = denominator;
    } else {
        throw std::runtime_error("Denominator should not be zero");
    }
    Reduction();
}
Rational& Rational::operator=(const Rational& rhs) {
    numerator = rhs.numerator;
    if (rhs.denominator != 0) {
        denominator = rhs.denominator;
    } else {
        throw std::runtime_error("Denominator should not be zero");
    }
    Reduction();
    return *this;
}
Rational& Rational::operator=(const int rhs) {
    return operator=(Rational(rhs));
}
Rational& Rational::operator+=(const Rational& rhs) {
    numerator = numerator * rhs.denominator + rhs.numerator*denominator;
    denominator *= rhs.denominator;
    Reduction();
    return *this;
}
Rational& Rational::operator+=(const int rhs) {
    return operator+=(Rational(rhs));
}
Rational& Rational::operator-=(const Rational& rhs) {
    numerator = numerator * rhs.denominator - rhs.numerator*denominator;
    denominator *= rhs.denominator;
    Reduction();
    return *this;
}
Rational& Rational::operator-=(const int rhs) {
    return operator-=(Rational(rhs));
}
Rational& Rational::operator*=(const Rational& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    Reduction();
    return *this;
}
Rational& Rational::operator*=(const int rhs) {
    return operator*=(Rational(rhs));
}
Rational& Rational::operator/=(const Rational& rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    Reduction();
    return *this;
}
Rational& Rational::operator/=(const int rhs) {
    if (rhs == 0) {
        throw std::runtime_error("Cannot be divided by zero");
    }
    return operator/=(Rational(rhs));
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational sum(lhs);
    sum += rhs;
    return sum;
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational diff(lhs);
    diff -= rhs;
    return diff;
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational prod(lhs);
    prod *= rhs;
    return prod;
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational quot(lhs);
    quot /= rhs;
    return quot;
}
void Rational::Reduction() {
    if ((numerator != 0) && (denominator != 0)) {
        int k = numerator % denominator;
        int div = 1;
        if (k != 0) {
            int n = numerator;
            int d = denominator;
            while (k != 0) {
                n = d; d = k;
                k = n % d;
            }
            div = d;
        }
        numerator /= div;
        denominator /= div;
    }
    if (numerator == denominator) {
        numerator = 1;
        denominator = 1;
    }
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << LeftBrace << numerator << separator << denominator << RightBrace;
    return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm) {
    char LeftBrace(0);
    char RightBrace(0);
    char slash(0);
    int numerator(0);
    int denominator(0);
    istrm >> LeftBrace >> numerator >> slash >> denominator >> RightBrace;
    if (istrm.good()) {
        if ((Rational::LeftBrace == LeftBrace) && (Rational::separator == slash)
            && (Rational::RightBrace) && (denominator != 0)) {
            Rational::numerator = numerator;
            Rational::denominator = denominator;
        } else {
            if (denominator == 0) {
                throw std::runtime_error("Denominator should not be zero");
            } else {
                throw std::runtime_error("Invalid input");
            }
        }
    }
    return istrm;
}
bool TestParse(const std::string& str) {
    std::istringstream istrm(str);
    Rational z;
    int exception_counter = 0;
    try {
        istrm >> z;
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        exception_counter++;
    }
    if (istrm.good() && exception_counter == 0) {
        std::cout << "Read success:    " << str << "->" << z << std::endl;
    } else {
        std::cout << "Read error:      " << str << "->" << z << std::endl;
    }
    return istrm.good() && exception_counter == 0;
}
