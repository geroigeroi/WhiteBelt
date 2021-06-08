#include <iostream>
using namespace std;

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

bool operator==(const Rational& lhs, const Rational& rhs) {
    if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
        return true;
    } else {
        return false;
    }
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
