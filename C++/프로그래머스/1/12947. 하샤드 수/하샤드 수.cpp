#include <string>
#include <vector>
#include <numeric>

using namespace std;

bool solution(int x) {
    int GetNum = x;
    vector<int> Num;
    
    while(0 < x){
        Num.push_back(x%10);
        x /= 10;
    }
    
    int Sum = 0;
    Sum = accumulate(Num.begin(), Num.end(), 0);
    
    if(GetNum % Sum == 0){
        return true;
    }else return false;
}