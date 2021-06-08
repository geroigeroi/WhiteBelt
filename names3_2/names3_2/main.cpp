//
//  main.cpp
//  names3_2
//
//  Created by  Mister on 02.11.2020.
//

#include <iostream>
#include <map>
#include <vector>

class Person {
private:
    std::map<int, std::string, std::greater<int>> FirstNames;
    std::map<int, std::string, std::greater<int>> LastNames;
    int birthYear;
    
public:
    Person(const std::string& FName, const std::string& LName, const int year) {
        FirstNames.insert(std::make_pair(year, FName));
        LastNames.insert(std::make_pair(year, LName));
        birthYear = year;
    }
    void ChangeFirstName(const int& year, const std::string& first_name) {
        if (year >= birthYear) {  // Работаем только если год больше или равен году рождения
            // FirstNames.insert(std::make_pair(year, first_name));
            FirstNames[year] = first_name;
        }
    }
    
    void ChangeLastName(const int& year, const std::string& last_name) {
        if (year >= birthYear) {  // Работаем только если год больше или равен году рождения
            // LastNames.insert(std::make_pair(year, last_name));
            LastNames[year] = last_name;
        }
    }
    
    std::string GetFullName(const int& year) const {
        std::string outputFN, outputLN;
        if (year < birthYear) { // Запрашиваем имя персоны, которая еще не родилась
            outputFN = "No person";
        } else {
            std::map<int, std::string> :: const_iterator itFN;  // Итератор для имени, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
            std::map<int, std::string> :: const_iterator itLN;  // Итератор для фамилии, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
            itFN = FirstNames.lower_bound(year);
            itLN = LastNames.lower_bound(year);
            outputFN = itFN->second;
            outputLN = itLN->second;
        }
        return outputFN + " " + outputLN;
    }
    
    std::string GetFullNameWithHistory(int year) const {
        std::string outputWithHistory;
        std::string outputFN, outputLN;
        if (year < birthYear) { // Запрашиваем имя персоны, которая еще не родилась
            outputWithHistory = "No person";
            return outputWithHistory;
        } else {
            std::map<int, std::string> :: const_iterator itFN;  // Итератор для имени, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
            std::map<int, std::string> :: const_iterator itLN;  // Итератор для фамилии, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
            itFN = FirstNames.lower_bound(year);
            itLN = LastNames.lower_bound(year);
            if (itFN->first != birthYear) {  // Если больше одного имени, то надо форматированно выводить
                std::vector<std::string> FNFormated;  // Будем складывать в этот вектор все имена
                FNFormated.push_back(itFN->second);  // Первое aka основное имя добавили
                std::vector<std::string> FirstNames_vec;  // Временный вектор
                for (itFN; itFN != FirstNames.end(); ++itFN) {
                    FirstNames_vec.push_back(itFN->second);
                }
                for (int i = 0; i < FirstNames_vec.size() - 1; ++i) {  // Перебираем фамилии
                    if (FirstNames_vec[i] != FirstNames_vec[i + 1]) {
                        FNFormated.push_back(FirstNames_vec[i + 1]);
                    }
                }
                for (auto i = 1; i < FNFormated.size(); ++i) {
                    outputFN.append(FNFormated[i] + ", ");
                }
                outputFN = outputFN.erase(outputFN.size() - 2);
                outputFN = FNFormated[0] + " (" + outputFN + ")";
            } else {  // Имя одно (то, которое при рождении) –– выводим только его
                outputFN = itFN->second;
                
            }
            if (itLN->first != birthYear) {  // Если больше одной фамилии, то надо форматированно выводить
                std::vector<std::string> LNFormated;  // Будем складывать в этот вектор все фамилии
                LNFormated.push_back(itLN->second);  // Первую aka основную фамилию добавили
                std::vector<std::string> LastNames_vec;  // Временный вектор
                for (itLN; itLN != LastNames.end(); ++itLN) {
                    LastNames_vec.push_back(itLN->second);
                }
                for (int i = 0; i < LastNames_vec.size() - 1; ++i) {  // Перебираем фамилии
                    if (LastNames_vec[i] != LastNames_vec[i + 1]) {
                        LNFormated.push_back(LastNames_vec[i + 1]);
                    }
                }
                for (auto i = 1; i < LNFormated.size(); ++i) {
                    outputLN.append(LNFormated[i] + ", ");
                }
                outputLN = outputLN.erase(outputLN.size() - 2);
                outputLN = LNFormated[0] + " (" + outputLN + ")";
            } else {  // Фамилия одна (та, которая при рождении) –– выводим только её
                outputLN = itLN->second;
            }
        }
        outputWithHistory = outputFN + " " + outputLN;
        return outputWithHistory;
    }
};

int main() {
    
    Person person("P", "Sergeeva", 1960);
    person.ChangeFirstName(1961, "Appolinaria");
    
    person.ChangeFirstName(1962, "Polina");
    person.ChangeFirstName(1963, "Appolinaria");
    
    person.ChangeLastName(1963, "Sergeeva");
    person.ChangeLastName(1964, "Volkova");
    person.ChangeLastName(1966, "Volkova-Sergeeva");
    // std::cout << person.GetFullNameWithHistory(1965) << std::endl;
    
    for (int year : {1960, 1964, 1965, 1966}) {
      std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }
    
    return 0;
}
