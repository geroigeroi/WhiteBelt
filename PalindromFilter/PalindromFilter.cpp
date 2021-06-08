std::vector<std::string> PalindromFilter (std::vector<std::string> words, int minLength) {
    int sz = (int)words.size();          // Количество элементов вектора
    int sz_string;                       // Длина каждого элемента вектора
    for (int i = 0; i <= sz - 1; ++i) {      // Перебираем каждый элемент начального вектора
        sz_string = (int)words[i].size();             // Размер каждой подряд строки из начального вектора
        if (sz_string < minLength) {
            words.erase(words.begin() + i);
            sz--;
        }
    }
    
    int mdl;                // Значение середины строки
    std::string defin_str;  // Записываем каждый элемент вектора в эту переменную и работаем уже с этой строковой переменной
    int defin_str_size;     // Длина каждой такой записанной строки
    sz = (int)words.size();
    for (int i = 0; i <= sz - 1; ++i) {
        defin_str = words[i];
        defin_str_size = (int)defin_str.size();
        mdl = defin_str_size / 2;
        for (int j = 0; j < mdl; ++j) {
            if (defin_str[j] != defin_str[defin_str_size - 1]) {
                words.erase(words.begin() + i);
                break;
            }
            --defin_str_size;
        }
    }
    return words;
}