std::vector<int> Reversed(const std::vector<int>& v) {
    int sz = (int)v.size();
    std::vector<int> withReverse(sz);
    
    for (int i = sz - 1; i >= 0; i--) {
        withReverse[sz - 1 - i] = v[i];
        
    }
    return withReverse;
}