#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string text = "";

    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i]))
        {
            text += static_cast<char>(65+((s[i]-65+n)%26));
        } else if(islower(s[i])) 
        { 
            text += static_cast<char>(97+((s[i]-97+n)%26));
        } else
        {
            text += " ";
        }
    }        
    return text; 
}