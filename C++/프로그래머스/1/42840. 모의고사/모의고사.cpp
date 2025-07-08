#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> student_0 = {1, 2, 3, 4, 5};
    vector<int> student_1 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student_2 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> answerScore = {0, 0, 0};
    vector<int> answer;
    
    for(int i = 0; i < answers.size(); ++i)
    {
        if(answers[i] == student_0[i % student_0.size()])
        {
            answerScore[0]++;
        }
        if(answers[i] == student_1[i % student_1.size()])
        {
            answerScore[1]++;
        }
        if(answers[i] == student_2[i % student_2.size()])
        {
            answerScore[2]++;
        }
    }
    
    int High = 0;
    High = max(answerScore[0], max(answerScore[1], answerScore[2]));
    for(int i = 0; i < 3; ++i)
    {
        if(High == answerScore[0] && High > 0)
        {
            answer.push_back(1);
            answerScore[0] = -1;
        }else 
        if(High == answerScore[1] && High > 0)
        {
            answer.push_back(2);
            answerScore[1] = -1;
        }else
        if(High == answerScore[2] && High > 0)
        {
            answer.push_back(3);
            answerScore[2] = -1;
        }
    }
    
    return answer;
}