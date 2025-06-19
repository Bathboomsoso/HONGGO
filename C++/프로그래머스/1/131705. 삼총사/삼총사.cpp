#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for(int i = 0; i < number.size(); i++)
    {
        for(int j = i+1; j < number.size(); j++)
        {
            for(int a = j+1; a < number.size(); a++)
            {
                if((number[i]+number[j]+number[a]) == 0)
                {
                  answer++;  
                }
                    
            }
        }
    }

    
    return answer;
}