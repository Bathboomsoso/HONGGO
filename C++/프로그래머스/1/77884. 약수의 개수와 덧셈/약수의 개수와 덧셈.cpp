#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int num = 0;
    
    for(int i = left; i <= right; i++){  // 범위 로직
        for(int j = 1; j <= i; j++){ // 수 약수 검사 로직
            if(i % j == 0){ // 약수 판별
                num++; // 개수 
            }
        }
        if(num % 2 == 0){
            answer += i;
            num = 0;
        }else{
            answer -= i;
            num = 0;
        }
    }
    
    return answer;
}