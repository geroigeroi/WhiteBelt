//
//  main.cpp
//  SortedStrings
//
//  Created by  Mister on 18.10.2020.
//

#include <iostream>
#include <vector>
#include <set>

class SortedStrings {
public:
  void AddString(const std::string& s) {
      // добавить строку s в набор
      SortedStrings.push_back(s);
  }
  std::vector<std::string> GetSortedStrings() {
      // получить набор из всех добавленных строк в отсортированном порядке
      // std::vector<std::string> SortedVector;
      sort(SortedStrings.begin(), SortedStrings.end());
      return SortedStrings;
  }
private:
    // приватные поля
    std::vector<std::string> SortedStrings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const std::string& s : strings.GetSortedStrings()) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

int main() {
    SortedStrings strings;
      
      strings.AddString("first");
      strings.AddString("third");
      strings.AddString("second");
      PrintSortedStrings(strings);
      
      strings.AddString("second");
      PrintSortedStrings(strings);
    
    return 0;
}
