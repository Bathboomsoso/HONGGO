#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int sq1 = 0;
    int sq2 = 0;
    
    for(int i = 0; i < goal.size(); ++i)
    {
        if(cards1[sq1] == goal[i])
        {
            sq1++;
        }else if(cards2[sq2] == goal[i])
        {
            sq2++;
        }else{
            return "No";
        }
    }
    return "Yes";
}