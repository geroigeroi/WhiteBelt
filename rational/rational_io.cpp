#include <iostream>
#include <sstream>
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
