#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != ' ')
        {
            if(index % 2 == 0)
            {
                answer += toupper(s[i]);
            }else
            {
                answer += tolower(s[i]);
            }
            index++;
        }else 
        {
            answer += ' ';
            index = 0;
        }
        
    }
    return answer;
}