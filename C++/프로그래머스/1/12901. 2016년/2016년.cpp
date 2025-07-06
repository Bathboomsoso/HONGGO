#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> daysOfMonth = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> weeks = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int day = b;
    
    for(int i = 0; i < a - 1; ++i)
    {
        day += daysOfMonth[i];
    }
    cout << day << endl;
    answer += weeks[(day + 4)% 7]; 
    return answer;
}