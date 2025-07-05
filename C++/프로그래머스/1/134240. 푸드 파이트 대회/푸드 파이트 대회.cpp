#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int j;
    
    for(j = 1; j < food.size(); ++j)
    {
        for(int i = 0; i < trunc(food[j]/2); ++i)
        {
            answer += to_string(j);
        }
    }
    string right_food = answer;
    reverse(right_food.begin(), right_food.end());
    answer += to_string(0);
    answer += right_food;
    return answer;
}