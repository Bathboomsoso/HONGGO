#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> lastchar;
    
    for(int i = 0; i < s.size(); ++i)
    {
        char ch = s[i];
        
        if(lastchar.count(ch))
        {
            answer.push_back(i - lastchar[ch]);
        }else
        {
            answer.push_back(-1);
        }
        
        lastchar[ch] = i;
    }
    return answer;
}