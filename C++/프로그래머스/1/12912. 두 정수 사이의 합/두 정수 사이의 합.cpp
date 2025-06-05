#include <string>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;

long long solution(int a, int b) {
    vector<long long> Num;
    
    if(a > b){
        swap(a, b);
    }
    if(a == b){
        return a;
    }
    
    for(int i = a; i < b+1; ++i){
        Num.push_back(i);
    }
    
    long long Sum = accumulate(Num.begin(), Num.end(), 0LL);
    
    return Sum;
}