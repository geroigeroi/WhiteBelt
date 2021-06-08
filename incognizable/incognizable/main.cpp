//
//  main.cpp
//  incognizable
//
//  Created by  Mister on 04.11.2020.
//

#include <iostream>

class Incognizable {
private:
    int x, y;
    
public:
    Incognizable() {
        
    }
    Incognizable(int a, int b) {
        
    }
    Incognizable(int a) {
        
    }
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
}
