#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(int k, int m, vector<int> score) {
    vector<int> min;
    int box = (score.size()/m);
    int answer = 0;
    
    sort(score.begin(), score.end(), greater());
    
    for(int i = 1; i < box+1; ++i)
    {
        min.push_back(score[(i*m)-1]); // 상자의 최저값
        answer += min[i-1]*m;
    }
    
    return answer;
}