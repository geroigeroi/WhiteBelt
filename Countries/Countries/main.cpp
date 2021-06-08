//
//  main.cpp
//  Countries
//
//  Created by  Mister on 10/3/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

int main() {
    int Q;  // Количество операций
    int i = 0;
    std::string command;
    std::string country_about; // Используются в блоке ABOUT
    std::string old_country_name, new_country_name; // Используются в блоке RENAME
    std::string country_change, new_capital; // Используются в блоке CHANGE_CAPITAL
    std::map<std::string, std::string> base;
    std::vector<std::string> output;
    std::string tmp;
    std::string tmp2;
    
    
    std::cin >> Q;
    
    while(i < Q) {
        std::cin >> command;
        
        /* Вывод всех имеющихся пар Страна/Столица */
        if (command == "DUMP") {
            if (base.size() == 0) {  // Ни одна страна еще не добавлена
                output.push_back("There are no countries in the world");
            } else {  // Хотя бы одна пара страна/столица есть
                output.resize(i + 1);
                for (auto item : base) {
                    output[i] += (item.first + "/" + item.second + " ");
                }
            }
        } else {
            /* Вывод информации по конкретной стране */
            if (command == "ABOUT") {
                std::cin >> country_about;
                if (base.count(country_about) == 1) { // Такая страна есть
                    output.push_back("Country " + country_about + " " + "has capital " + base[country_about]);
                } else { // Такой страны не добавлено
                    output.push_back("Country " + country_about + " " + "doesn't exist");
                }
            }
            /* переименование страны */
            if (command == "RENAME") {
                std::cin >> old_country_name >> new_country_name;
                if (old_country_name == new_country_name || base.count(old_country_name) == 0 || base.count(new_country_name) == 1) { // новое название страны совпадает со старым; страны, которую хотим переименовать, не добавлена; страна, на которую хотим переименовать, уже добавлена
                    output.push_back("Incorrect rename, skip");
                } else {  // Переименовываем страну
                    tmp = old_country_name;  // Сохраняем старое название страны
                    tmp2 = base[old_country_name];  // Сохраняем столицу
                    base.erase(old_country_name);
                    base[new_country_name] = tmp2;
                    output.push_back("Country " + tmp + " with capital " + tmp2 + " has been renamed to " + new_country_name);
                }
            }
            /* Изменение столицы и добавление стран со столицей */
            if (command == "CHANGE_CAPITAL") {
                std::cin >> country_change >> new_capital;
                if (base.count(country_change) == 0) {  // Такой страны ранее не было в справочнике
                    base[country_change] = new_capital;
                    output.push_back("Introduce new country " + country_change + " " + "with capital " + new_capital);
                } else if (base[country_change] == new_capital) {  // Такая страна была и с такой же столицей
                    output.push_back("Country " + country_change + " " + "hasn't changed its capital");
                } else {  // Страна имела старую столицу и теперь меняет её на новую
                    tmp = base[country_change];
                    base[country_change] = new_capital;
                    output.push_back("Country " + country_change + " " + "has changed its capital from " + tmp + " to " + new_capital);
                }
            }
        }
        ++i;
    }
    for (auto x : output) {
        std::cout << x << std::endl;
    }
    return 0;
}
