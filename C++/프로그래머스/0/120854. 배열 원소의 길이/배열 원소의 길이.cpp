#include <string>
#include <vector>

using namespace std;

vector<int> solution(const vector<string> strlist) {
    vector<int> result;
    for (const string& s : strlist){
        result.push_back(s.length());
    }
    return result;
}