//
//  main.cpp
//  reversible_string
//
//  Created by  Mister on 30.10.2020.
//

#include <iostream>
#include <string>

class ReversibleString {
private:
    std::string ourString;

public:
    ReversibleString(std::string oneString) {
        ourString = oneString;
    }
    
    ReversibleString() {
        
    }
    
    std::string ToString() const {
        return ourString;
    }
    
    std::string Reverse () {
        std::string reversedString;
        
        for (int i = (int)ourString.size() - 1; i >= 0; --i) {
            reversedString = reversedString + ourString[i];
        }
        ourString = reversedString;
        return reversedString;
    }
    
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    std::cout << s.ToString() << std::endl;
    
    s.Reverse();
    const ReversibleString& s_ref = s;
    std::string tmp = s_ref.ToString();
    std::cout << tmp << std::endl;
    
    ReversibleString empty;
    std::cout << '"' << empty.ToString() << '"' << std::endl;
    
    return 0;
}
