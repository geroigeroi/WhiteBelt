//
//  main.cpp
//  MiddleTemp
//
//  Created by  Mister on 9/18/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    int N;  // Количество дней
    int sum = 0;
    int average; // Среднее арифметическое температуры
    int days_high = 0;  // Количество дней, когда температура была выше средней
    std::vector<int> numbers_days;  // Порядковые номера дней, когда температура была выше средней
    std::cin >> N;
    std::vector<int> temperature(N);
    
    /* Ввод значений температуры */
    for (auto& s : temperature) {
        std::cin >> s;
    }
    /* Вычисляем среднее арифметическое температуры */
    for (auto s : temperature) {
        sum = sum + s;
    }
    average = sum / N;
    
    /* Выводим количество дней, в которых значение температуры было выше среднего арифметического, и номера этих дней */
    for (int i = 0; i < N; ++i) {
        if (temperature[i] > average) {
            days_high++;
            numbers_days.push_back(i);
        }
    }
    
    std::cout << days_high << std::endl;
    for (auto s : numbers_days) {
        std::cout << s << " ";
    }
    
    return 0;
}
