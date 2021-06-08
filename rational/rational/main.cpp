//
//  main.cpp
//  rational
//
//  Created by  Mister on 13.11.2020.
//

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

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
            throw std::invalid_argument("Zero division");
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
        throw std::domain_error("Denominator is zero");
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
    
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
    
}
