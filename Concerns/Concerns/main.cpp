//
//  main.cpp
//  Concerns
//
//  Created by  Mister on 9/20/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    int Q;  // Количество операций
    int i = 0;
    std::string command;
    int day;
    int current_month = 0;
    std::string business;
    std::vector<int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::vector<std::string>> working_month(months[current_month]);
    std::vector<int> quantity_of_businesses;
    std::vector<std::vector<std::string>> name_of_business(1);
    int dump_index = 0;
    
    std::cin >> Q;
    
    while (i < Q) {
        std::cin >> command;
        if (command == "NEXT") {
            current_month++;  // Увеличили месяц на один
            if (current_month == 12) {  // Если увеличенный месяц = 12 (в нумерации с 0), значит
                current_month = 0;  // Обнуляем месяц на нулевой (январь)
            }
            if (months[current_month] < months[current_month - 1]) {  // Проверяем меньше ли количество дней во вновь вступившем месяце, чем в предыдущем
                for (int k = months[current_month] + 1; k <= months[current_month - 1]; ++k) { // Перебираем все такие дни, когторых нет во вновь вступившем месяце, но которые были в прошлом
                    for (auto m : working_month[k - 1]) {  // m - дела всех таких дней
                        working_month[months[current_month] - 1].push_back(m);  // Записываем все такие дела в последний день вступившего месяца
                    }
                }
            }
            working_month.resize(months[current_month]);  // Меняем количество дней
        }
        else if (command == "DUMP") {
            std::cin >> day;
            quantity_of_businesses.push_back((int)working_month[day - 1].size());  // Пишем количество дел в вектор типа int
            if (working_month[day - 1].size() != 0) {  // Тут условие, что если дел в данном мне нет, то в соответствующий порядковый номер вектора name_of_business запишем просто пробел
                for (int j = 0; j <= working_month[day - 1].size() - 1; ++j) {  // Перебираем все элементы соответствующего дня в векторе векторов
                    name_of_business[dump_index].push_back(working_month[day - 1][j]);  // В вектор, который будем выводить, записываем название каждого дела соответствующего дня
                }
            } else {
                name_of_business[dump_index].push_back(" ");  // Если дел нет, то впишем в выходной вектор пробел
            }
            
            // std::cout << working_month[day - 1].size() << " " ;
            dump_index++;
            name_of_business.resize(dump_index + 1);  // Ресайзим выходной вектор на перспективу следущей в него записи
        }
        else if (command == "ADD") {
            std::cin >> day >> business;
            working_month[day - 1].push_back(business);  // Считали день, считали дело. Записали.
        }
        ++i;
    }
    /* Здесь вывод */
    for (int n = 0; n <= quantity_of_businesses.size() - 1; ++n) {
        std::cout << quantity_of_businesses[n] << " ";
        for (int g = 0; g <= name_of_business[n].size() - 1;++g) {
            std::cout << name_of_business[n][g] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
