//
//  main.cpp
//  Buses1
//
//  Created by  Mister on 10/6/20.
//  Copyright © 2020 Home. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

int main() {
    int Q;  // Количество операций
    int i = 0;
    std::string command;
    std::string bus, stop;
    int stop_count;
    std::map<std::string, std::vector<std::string>> buses;
    std::string names_of_stations;
    bool stop_finded = false;
    
    
    std::cin >> Q;
    
    while(i < Q) {
        std::cin >> command;
        if (command == "ALL_BUSES") {
            // Здесь вывод всех маршрутов с остановками
        } else if (command == "STOPS_FOR_BUS") {
            std::cin >> bus;
            // Здесь вывод названия всех остановок данного маршрута со списком автобусов, на которые можно пересесть
            if (buses.count(bus) == 0) {  // Если маршрута с таким названием не добавлено, то вывводим No bus
                std::cout << "No bus" << std::endl;
            } else {
                for (auto u : buses[bus]) {
                    std::cout << "Stop " << u << ": ";
                    for (auto k : buses) {
                        for (auto l : k.second) {
                            if (l == u) {
                                std::cout << k.first << " ";
                            }
                        }
                    }
                }
            }
        } else if (command == "BUSES_FOR_STOP") {
            std::cin >> stop;
            // Здесь вывод названий всех маршрутов, проходящих через данную остановку
            for (auto k : buses) {
                for (auto l : k.second) {
                    if (l == stop) {  // Если нашли остановку, то выводим соответствующее название маршрута
                        std::cout << k.first << " ";
                        stop_finded = true;  // Показываем, что остановка хотя бы раз нашлась
                    }
                }
            }
            if (stop_finded != true) {
                std::cout << "No stop";
            }
            std::cout << std::endl;
        } else if (command == "NEW_BUS") {
            std::cin >> bus >> stop_count;
            for (int j = 0; j <= stop_count - 1; ++j) {
                std::cin >> names_of_stations;
                buses[bus].push_back(names_of_stations);
            }
        }
        ++i;
    }
    return 0;
}
