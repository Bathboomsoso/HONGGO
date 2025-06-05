#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
vector<int> Num;
    while(n > 0){
        int GetNum = 0;
        GetNum = n % 10;
        n /= 10;
        Num.push_back(GetNum);
    }

n = 0;
sort(Num.begin(), Num.end(), greater<int>());

    for(int i; i < Num.size(); ++i){
        n *= 10;
        n += Num[i];
    }
return n;
}