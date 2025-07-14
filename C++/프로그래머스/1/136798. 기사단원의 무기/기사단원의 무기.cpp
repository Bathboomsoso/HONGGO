#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> Count(int n) {
    vector<int> counts(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            counts[j]++;
        }
    }
    return counts;
}

int solution(int number, int limit, int power) {
    vector<int> List = Count(number);

    long long answer = 0;
    
    for (int i = 1; i <= number; ++i) {
        int count = List[i]; 
        
        if (count > limit) {
            answer += power;
        } else {
            answer += count;
        }
    }
    return answer;
}