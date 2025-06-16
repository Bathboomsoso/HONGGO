#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    auto answer = it - seoul.begin();
    
    string st = "김서방은 "+ to_string(answer)+"에 있다";
    return st;
}