#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); ++i)
    {
        vector<int> temp(array.begin() + commands[i][0] - 1, array.end() - (array.size() - commands[i][1]));
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2]-1]);

        temp.clear();
    }
    return answer;
}