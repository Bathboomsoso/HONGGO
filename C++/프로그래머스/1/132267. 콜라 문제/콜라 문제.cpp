#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a)
    {
        n -= a;
        answer += b;
        n += b;
    }
    
    return answer;
}