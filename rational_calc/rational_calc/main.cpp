//
//  main.cpp
//  rational_calc
//
//  Created by  Mister on 15.11.2020.
//

#include <iostream>
#include <sstream>
#include <exception>

using namespace::std;

class Rational {
private:
    int numerator;
    int denominator;
    
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int num_check, int denom_check) {
        if (denom_check == 0) {
            throw std::invalid_argument("Invalid argument");
        }
        if (num_check == 0) {
            denom_check = 1;
        }
        int num_temp = num_check, denom_temp = denom_check;
        num_check = abs(num_check);
        denom_check = abs(denom_check);
        while (num_check != 0 && denom_check != 0) {
            if (num_check > denom_check) {
                num_check = num_check % denom_check;
            } else {
                denom_check = denom_check % num_check;
            }
        }
        int gcd = denom_check + num_check;
        numerator = num_temp / gcd;
        denominator = denom_temp / gcd;
        if (denominator < 0) {
            denominator = - denominator;
            numerator = - numerator;
        }
    }
    int Numerator() const {
        
        return numerator;
    }
    int Denominator() const {
        
        return denominator;
    }
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw std::domain_error("Division by zero");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}
bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    } else {
        return false;
    }
}
ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/"
           << rational.Denominator();
    return stream;
}
istream& operator>>(istream& stream, Rational& rational) {
    int numinatorInput, denominatorinput;
    char fractionLine;
    if (stream >> numinatorInput) {
        stream >> fractionLine;
        if (fractionLine == '/') {
            if (stream >> denominatorinput) {
                rational = Rational(numinatorInput, denominatorinput);
            }
        }
    }
    return stream;
}
bool operator<(const Rational& lhs, const Rational& rhs) {
    Rational diff = lhs - rhs;
    if(diff.Numerator() >= 0) {
        return false;
    } else {
        return true;
    }
}
bool operator>(const Rational& lhs, const Rational& rhs) {
    Rational diff = lhs - rhs;
    if(diff.Numerator() < 0) {
        return false;
    } else {
        return true;
    }
}


int main() {
    
    Rational fraction1, fraction2, result;
    char operation;
    try {
    std::cin >> fraction1 >> operation >> fraction2;
        if (operation == '/') {
            result = fraction1 / fraction2;
        }
        if (operation == '*') {
            result = fraction1 * fraction2;
        }
        if (operation == '+') {
            result = fraction1 + fraction2;
        }
        if (operation == '-') {
            result = fraction1 - fraction2;
        }

    } catch (invalid_argument& invArg) {
        std::cout << invArg.what() << "\n";
        return 0;
    } catch (domain_error& divByZero) {
        std::cout << divByZero.what() << "\n";
        return 0;
    }
    std::cout << result << "\n";
    return 0;
    
}
