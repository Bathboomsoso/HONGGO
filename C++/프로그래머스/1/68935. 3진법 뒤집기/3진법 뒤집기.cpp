#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int a = n;
    string base = "";
    
    while(a / 3 != 0){ // 3진수 변환
        base += (a % 3 + '0');
        a /= 3;
    }
    base += (a % 3 + '0');
    
    int count = 1;
    
    int strsize = base.size();
    for(auto i = base.rbegin(); i != base.rend(); i++){
        answer += (*i - '0') * count;
        count *= 3;
        cout << answer << endl;
    }
    
    return answer;
}