#pragma once
#include <iostream>
#include <sstream>
#include <exception>

class Rational {
 public:
    Rational() {}
    explicit Rational(const int numerator);
    Rational(const int numerator, const int denomirator);

    bool operator==(const Rational& rhs) {
        return numerator == rhs.numerator && denominator == rhs.denominator; 
    }
    bool operator!=(const Rational& rhs) { return !(operator==(rhs)); }
    Rational& operator=(const Rational& rhs);
    Rational& operator=(const int rhs);
    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const int rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const int rhs);
    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const int rhs);
    void Reduction();
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);
    static const char LeftBrace{ '{' };
    static const char separator{ '/' };
    static const char RightBrace{ '}' };

 private:
    int numerator{ 0 };
    int denominator{ 1 };
};
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
inline  std::istream& operator>>(std::istream& istrm, Rational& rhs);
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
bool TestParse(const std::string& str);

