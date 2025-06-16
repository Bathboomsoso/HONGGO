#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    int lenth = phone_number.size();
    
    for(int i = 0; i < lenth - 4; i++){
        answer += "*";
    }
    
    answer += phone_number.substr(lenth - 4, 4);
    
    return answer;
}