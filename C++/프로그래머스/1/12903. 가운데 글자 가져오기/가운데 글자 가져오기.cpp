#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int lenth = s.size();
    
    if(lenth % 2 == 0){
        answer = s.substr(lenth / 2 - 1, 2);
    }else if(lenth % 2 != 0){
        answer = s.substr(lenth / 2, 1);
    }
    return answer;
}