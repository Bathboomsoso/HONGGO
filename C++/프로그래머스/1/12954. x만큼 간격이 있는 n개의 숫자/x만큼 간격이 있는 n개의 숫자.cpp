#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
vector<long long> answer(1, x);
answer.reserve(n);
    
    for(int i = 1; i < n; ++i)
    {
        answer.push_back(answer.back() + x);
    }
    
    return answer;
}

// 곱셈 말고 덧셈이 좀더 좋을것 같다. []
// capacity??