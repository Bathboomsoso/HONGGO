#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> stg;
    
    for(int i = 0; i < score.size(); ++i) // 일수
    {
        stg.push_back(score[i]);
        sort(stg.begin(), stg.end());
        if(stg.size() > k)
        {
            stg.erase(stg.begin());    
        }
        answer.push_back(stg[0]); // 최하 점수 발표
    }
    return answer;
}