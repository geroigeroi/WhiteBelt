//
//  main.cpp
//  Names1
//
//  Created by  Mister on 19.10.2020.
//

#include <iostream>
#include <vector>
#include <map>

class Person {
private:
    // приватные поля
    std::map< int, std::vector<std::string>, std::greater<int> > OnePerson;  // Словарь создаем с сортировкой в порядке уменьшения ключей
    int birthYear;
public:
    
    Person(const std::string& FName, const std::string& LName, const int& year) {
        std::vector<std::string> FL(2);
        FL[0] = FName;
        FL[1] = LName;
        OnePerson.insert(std::make_pair(year, FL));
        birthYear = year;
    }
    
    std::string CheckLN(const std::vector<std::string>& LNforOutput) {
        std::string preparedLN;
        std::vector<std::string> LNFormated;
        LNFormated.push_back(LNforOutput[0]);
        if (LNforOutput.size() > 1) {  // В элементе 0 хранится основная фамилия. А если размер больше 1, значит там есть еще значения, которые надо отсортировать и вывести
            for (int i = 0; i < LNforOutput.size() - 1; ++i) {  // Перебираем фамилии
                if (LNforOutput[i] != LNforOutput[i + 1]) {
                    LNFormated.push_back(LNforOutput[i + 1]);
                }
            }
            if (LNFormated.size() == 1) {  // Получилась одна неповторяющаяся фамилия, её и берем
                preparedLN = LNFormated[0];
            } else {  // Неповторяющихся фамилий несколько, форматируем их
                for (int i = 1; i < LNFormated.size(); ++i) {
                    preparedLN.append(LNFormated[i] + ", ");
                }
                preparedLN = preparedLN.erase(preparedLN.size() - 2);
                preparedLN = LNFormated[0] + " (" + preparedLN + ")";
            }
            
        } else {  // Только один элемент –– фамилия на вывод, её и берем
            preparedLN = LNforOutput[0];
        }
        return preparedLN;
    }
    
    std::string CheckFN(const std::vector<std::string>& FNforOutput) {
        std::string preparedFN;
        std::vector<std::string> FNFormated;
        FNFormated.push_back(FNforOutput[0]);
        if (FNforOutput.size() > 1) {  // В элементе 0 храниться основное имя. А если размер больше 1, значит там есть еще значения, которые надо в скобках вывести
            for (int i = 0; i < FNforOutput.size() - 1; ++i) {  // Перебираем фамилии
                if (FNforOutput[i] != FNforOutput[i + 1]) {
                    FNFormated.push_back(FNforOutput[i + 1]);
                }
            }
            for (int i = 1; i < FNFormated.size(); ++i) {
                preparedFN.append(FNFormated[i] + ", ");
            }
            preparedFN = preparedFN.erase(preparedFN.size() - 2);
            preparedFN = FNFormated[0] + " (" + preparedFN + ")";
        } else {  // Только один элемент –– имя на вывод, его и берем
            preparedFN = FNforOutput[0];
        }
        return preparedFN;
    }
    
    
    void AddAnyName(const int& year, const std::string& name, bool isFirstName) {
        std::vector<std::string> vectorName;  // Создали словарь из двух строк: имя и фамилия
        vectorName.resize(2); // Выделяем в векторе две строки: для имени и фамилии
        if (isFirstName == true) {  // Добавляем ИМЯ
            vectorName[0] = name;
        } else {  // Добавляем ФАМИЛИЮ
            vectorName[1] = name;
        }
        OnePerson.insert(std::make_pair(year, vectorName));  // Добавили в словарь пару год –– вектор с внесенным именем
    }
    
    
    void ChangeFirstName(const int& year, const std::string& first_name) {
        if (year > birthYear) {
            bool isFirstName = true;
            if (OnePerson.empty() == false) {  // Если НЕ пустой, т.е. уже НЕ первое внесение
                std::vector<std::string> addedName;
                addedName.resize(2);
                if (OnePerson.count(year) == 1) {  // Проверка, что этот год уже был добавлен ранее. Тогда запишем в эту же пару
                    addedName[1] = OnePerson[year][1];  // Взял из добавленного ранее года сохраненное там значение фамилии
                }
                addedName[0] = first_name;
                OnePerson[year] = addedName;
                
            } else {  // Если пустой, т.е. это первое добавление
                AddAnyName(year, first_name, isFirstName);
            }
        }
    }
    
    void ChangeLastName(const int& year, const std::string& last_name) {
        if (year > birthYear) {
            bool isFirstName = false;
            if (OnePerson.empty() == false) {  // Если НЕ пустой!
                std::vector<std::string> addedName;
                addedName.resize(2);
                if (OnePerson.count(year) == 1) {  // Проверка, что этот год уже был добавлен ранее. Тогда запишем в эту же пару
                    addedName[0] = OnePerson[year][0];  // Взял из добавленного ранее года сохраненное там значение имени
                }
                addedName[1] = last_name;
                OnePerson[year] = addedName;
            } else {  // Если пустой, т. е. это первое добавление
                AddAnyName(year, last_name, isFirstName);
            }
        }
    }
    
    
    std::string GetFullName(const int& year) {
        std::string output;
        if (year > birthYear) {
            return output = "No person";
        } else {
            if (OnePerson.empty() == true) {  // Сразу проверяем, что если ничего внесено не было, то и проверять нечего.
                return output = "Incognito";
            }
            std::map<int, std::vector<std::string>> :: iterator it_begin = OnePerson.end(); // Итератор на начало словаря (сортировка словаря –– обратная)
            std::string LNforOutput, FNforOutput;
            it_begin--;
            if ((*it_begin).first > year) {  // Если проверяемый год меньше самого меньшего уже добавленного года
                return output = "Incognito";
            }
            std::map<int, std::vector<std::string>> :: iterator it;  // Итератор, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
            it = OnePerson.lower_bound(year);
            if ((*it).second[0] == "") {  // Если имени нет, но есть фамилия
                LNforOutput = (*it).second[1];  // Сохранили фамилию для последующего вывода
                for (it; it != OnePerson.end(); ++it) {  // Движемся по годам в сторону уменьшения года
                    if ((*it).second[0] != "") {  // Нашли имя
                        FNforOutput = (*it).second[0];
                        return output = FNforOutput + " " + LNforOutput;
                    }
                }
                return output = LNforOutput + " with unknown first name";
            } else if ((*it).second[1] == "") {  // Если фамилии нет, но есть имя
                FNforOutput = (*it).second[0];  // Сохранили имя для последующего вывода
                for (it; it != OnePerson.end(); ++it) {  // Движемся по годам в сторону уменьшения года
                    if ((*it).second[1] != "") {  // Нашли фамилию
                        LNforOutput = (*it).second[1];
                        return output = FNforOutput + " " + LNforOutput;;
                    }
                }
                return output = FNforOutput + " with unknown last name";
            } else {  // Тот случай, когда ранее для данного года было добавлено как имя, так и фамилия. А значит либо то, либо другое искать, двигаясь по годам назад, не нужно
                FNforOutput = (*it).second[0];
                LNforOutput = (*it).second[1];
                return output = FNforOutput + " " + LNforOutput;
            }
        }
    }
    
    // получить все имена и фамилии по состоянию на конец года year
    std::string GetFullNameWithHistory(int year) {
        std::string outputWithHistory;
        if (year > birthYear) {
            return outputWithHistory = "No person";
        } else {
            if (OnePerson.empty() == true) {  // Сразу проверяем, что если ничего внесено не было, то и проверять нечего.
                return outputWithHistory = "Incognito";
            }
            std::map<int, std::vector<std::string>> :: iterator it_begin = OnePerson.end(); // Итератор на начало словаря (сортировка словаря –– обратная)
            std::vector<std::string> LNforOutput, FNforOutput;
            it_begin--;
            if ((*it_begin).first > year) {  // Если проверяемый год меньше самого меньшего уже добавленного года
                return outputWithHistory = "Incognito";
            }
            std::map<int, std::vector<std::string>> :: iterator it;  // Итератор, который будет искать запись года, который НЕ БОЛЬШЕ (меньшая либо равная) входного
            it = OnePerson.lower_bound(year);
            
            if ((*it).second[0] == "") {  // Если имени нет, но есть фамилия
                /*  Проходимся по всем нижележащим годам и ищем имена и фамилии в прошлом  */
                
                
                for (it; it != OnePerson.end(); ++it) {  // Движимся по годам в сторону уменьшения года
                    if ((*it).second[1] != "") {  // Нашли фамилию
                        LNforOutput.push_back((*it).second[1]);
                    }
                    
                    if ((*it).second[0] != "") {  // Нашли имя
                        FNforOutput.push_back((*it).second[0]);
                    }
                }
                
                std::string outputFN;
                if (FNforOutput.empty() == true) {  // Имён в прошлом добавлено не было
                    outputFN = " with unknown first name";
                    outputWithHistory = CheckLN(LNforOutput) + outputFN;
                } else if (FNforOutput.size() == 1) {  // Было только одно имя, его и выводим
                    outputFN = FNforOutput[0];
                    outputWithHistory = outputFN + " " + CheckLN(LNforOutput);
                } else {  // Имен было больше одного, выводим форматированно в соответствие с условием задачи
                    std::string preparedFN;
                    std::vector<std::string> FNFormated;
                    FNFormated.push_back(FNforOutput[0]);
                    for (int i = 0; i < FNforOutput.size() - 1; ++i) {
                        if (FNforOutput[i] != FNforOutput[i + 1]) {
                            FNFormated.push_back(FNforOutput[i + 1]);
                        }
                    }
                    for (int i = 1; i < FNFormated.size(); ++i) {
                        outputFN.append(FNFormated[i] + ", ");
                    }
                    outputFN = outputFN.erase(outputFN.size() - 2);
                    outputFN = FNFormated[0] + " (" + outputFN + ")";
                    outputWithHistory = outputFN + " " + CheckLN(LNforOutput);
                }
                
            } else if ((*it).second[1] == "") {  // Если фамилии нет, но есть имя
                for (it; it != OnePerson.end(); ++it) {  // Движимся по годам в сторону уменьшения года
                    if ((*it).second[1] != "") {  // Нашли фамилию
                        LNforOutput.push_back((*it).second[1]);
                    }
                    if ((*it).second[0] != "") {  // Нашли имя
                        FNforOutput.push_back((*it).second[0]);
                    }
                }
                
                std::string outputLN;
                if (LNforOutput.empty() == true) {  // Фамилий в прошлом добавлено не было
                    outputLN = " with unknown last name";
                    outputWithHistory = CheckFN(FNforOutput) + outputLN;
                } else if (LNforOutput.size() == 1) {  // Было только одна фамилия, её и выводим
                    outputLN = LNforOutput[0];
                    outputWithHistory = CheckFN(FNforOutput) + " " + outputLN;
                } else {  // Фамилий несколько, сортируем как надо для вывода и выводим
                    std::string preparedLN;
                    std::vector<std::string> LNFormated;
                    LNFormated.push_back(LNforOutput[0]);
                    for (int i = 0; i < LNforOutput.size() - 1; ++i) {
                        if (LNforOutput[i] != LNforOutput[i + 1]) {
                            LNFormated.push_back(LNforOutput[i + 1]);
                        }
                    }
                    for (int i = 1; i < LNFormated.size(); ++i) {
                        outputLN.append(LNFormated[i] + ", ");
                    }
                    outputLN = outputLN.erase(outputLN.size() - 2);
                    outputLN = LNFormated[0] + " (" + outputLN + ")";
                    outputWithHistory = CheckFN(FNforOutput) + " " + outputLN;
                }
            } else {  // Если есть и фамилия, и имя
                for (it; it != OnePerson.end(); ++it) {  // Движимся по годам в сторону уменьшения года
                    if ((*it).second[1] != "") {  // Нашли фамилию
                        LNforOutput.push_back((*it).second[1]);
                    }
                    if ((*it).second[0] != "") {  // Нашли имя
                        FNforOutput.push_back((*it).second[0]);
                    }
                }
                outputWithHistory = CheckFN(FNforOutput) + " " + CheckLN(LNforOutput);
            }
            return outputWithHistory;
        }
        
    }
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    
    
    person.ChangeFirstName(1961, "Appolinaria");
    person.ChangeFirstName(1962, "Appolinaria");
    person.ChangeFirstName(1963, "Poli");
    
    person.ChangeLastName(1962, "Ivanova");
    for (int year : {1965, 1967}) {
        std::cout << person.GetFullNameWithHistory(year) << std::endl;
    }
      
      return 0;
}
