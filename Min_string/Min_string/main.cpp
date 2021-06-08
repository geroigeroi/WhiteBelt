//
//  main.cpp
//  Min_string
//
//  Created by  Mister on 04/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a < b) {
        if (a < c) {
            cout << a;
        } else {
            cout << c;
        }
    } else {
        if (c < b) {
            cout << c;
        } else {
            cout << b;
        }
    }
    return 0;
}
