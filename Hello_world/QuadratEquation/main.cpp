//
//  main.cpp
//  Hello_world
//
//  Created by  Mister on 01/07/2020.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    double D, x1, x2;
    cin >> a >> b >> c;
    D = b * b - 4 * a * c;        // Находим Дискриминант
    if (D >= 0) {
        if (a == 0) {             // Проверяем коэффициенты
            if (b == 0) {         // Если оба коэффициента a, b равны 0, то корней нет
                return 0;
            } else {              // Если же b не равен 0, то решаем как линейное уравнение. Получаем один корень
                x1 = -c / b;
                cout << x1;
                return 0;
            }
        }
        x1 = (- b + sqrt(D)) / (2 * a); // решаем стандартное квадратное уравнение
        x2 = (- b - sqrt(D)) / (2 * a); // находим два корня
        if (x1 == x2) {                 // если оба корня совпали (D = 0), то выводим корень один раз
            cout << x1;
            return 0;
        }
        cout << x1 << " " << x2;
    }
    return 0;
}
