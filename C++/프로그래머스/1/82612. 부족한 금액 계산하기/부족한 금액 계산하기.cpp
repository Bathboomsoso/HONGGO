#include <cmath>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long sumprice = 0;
    
    for(int i = 1; i <= count; ++i){
        sumprice += price * i;
    }
    
    answer = money - sumprice;
    
    if (answer < 0){
        return abs(answer);
    }else{
        return 0;
    }
}