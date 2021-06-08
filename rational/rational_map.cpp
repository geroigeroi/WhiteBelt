#include <iostream>
#include <map>
#include <set>
#include <vector>
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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
