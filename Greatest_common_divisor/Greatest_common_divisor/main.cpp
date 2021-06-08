//
//  main.cpp
//  Greatest_common_divisor
//
//  Created by  Mister on 04/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    int c;                            // Временная переменная, чтобы менять местами a и b
    vector<int> gcd_a;                // Вектор делителей числа а
    vector<int> gcd_b;                // Вектор делителей числа b
    int gcd_a_size, gcd_b_size;       // Количество делителей чисел a и b
    
    cin >> a >> b;
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            gcd_a.push_back(i);
        }
    }
    for (int j = 1; j <= b; ++j) {
        if (b % j == 0) {
            gcd_b.push_back(j);
        }
    }
    gcd_a_size = (int)gcd_a.size();
    gcd_b_size = (int)gcd_b.size();
    if (a > b) {                      // Меняем местами, чтобы первая переменная всегда была меньше
        c = a;
        a = b;
        b = c;
    }
    for (int i = gcd_a_size - 1; i >= 0; --i) {             // Перебираем все делители числа a, начиная с большего
      for (int j = gcd_b_size - 1; j >= 0; --j) {           // Перебираем все делители числа b, начиная с большего
            if (gcd_a[i] == gcd_b[j]) {                     // Когда найден совпадающий делитель,
                cout << gcd_a[i] << endl;                   // выводим его
                return 0;                                   // и завершаем программу
            }
        }
    }
    return 0;
}
