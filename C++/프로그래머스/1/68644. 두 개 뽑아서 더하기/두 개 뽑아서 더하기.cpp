#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int s = 0;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        for(int j = 1; j < numbers.size(); ++j)
        {
            if(i == j)
            {
                break;
            }
            s = numbers[i]+numbers[j];
            auto it = find(answer.begin(), answer.end(), s);
            
            if(it == answer.end())
            {
                answer.push_back(s);
            }
        }
        sort(answer.begin(), answer.end());
    }
    return answer;
}