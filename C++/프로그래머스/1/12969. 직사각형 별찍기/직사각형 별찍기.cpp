#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    string answer;
    
    for(int i = 0; i < a; i++){
        answer += '*';
    }
    for(int i = 0; i < b; i++){
        cout << answer << endl;
    }
   
    
    
    return 0;
}