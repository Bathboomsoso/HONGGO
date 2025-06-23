#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    //int num2 = stoi(p);
    string a;
    
    for(int i = 0; i < t.size()-p.size()+1; ++i)
    {
        a = "";
        for(int j = 0; j < p.size(); ++j)
        {
            a += t[i+j];
        }
        //int num1 = stoi(a);
        if(p >= a)
        {
            answer++;
        }
    }
    
    return answer;
}