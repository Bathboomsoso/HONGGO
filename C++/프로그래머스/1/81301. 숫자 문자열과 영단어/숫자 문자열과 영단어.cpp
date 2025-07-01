#include <string>
#include <vector>
#include <algorithm>

int solution(std::string s) {
    std::vector<std::pair<std::string, std::string>> words = {
        {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"},
        {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

    for (const auto& pair : words) 
    {
        std::string word = pair.first;
        std::string digit = pair.second;

        size_t a = s.find(word); 
        while (a != std::string::npos) 
        { 
            s.replace(a, word.length(), digit); 
            a = s.find(word, a + digit.length());
        }
    }
    return std::stoi(s);
}