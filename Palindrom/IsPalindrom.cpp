bool IsPalindrom(std::string w) {
    int sz;                         // Размер строки
    int mdl;                        // Значение середины строки
    sz = (int)w.size();
    mdl = sz / 2;
        for (int i = 0; i < mdl; ++i){
            if (w[i] == w[sz - 1]) {
                --sz;
            } else {
                return false;
            }
        }
    return true;
}