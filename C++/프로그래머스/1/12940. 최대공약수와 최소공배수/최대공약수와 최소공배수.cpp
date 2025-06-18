#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    
    int s = min(n, m);
    int g = max(n, m);
    
    for(int i = g; i <= g; --i){
        if(n % i == 0 && m % i == 0){
            answer[0] = i;
            break;
        }
    }
    
    while(1){
        if(g % n == 0 && g % m == 0){
            answer[1] = g;
            break;
        }
        g++;
    }
    
    
    
    return answer;
}