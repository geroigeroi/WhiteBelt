void MoveStrings (std::vector<std::string>& source, std::vector<std::string>& destination) {
    for (auto x : source) {
        destination.push_back(x);
    }
    source.clear();
}