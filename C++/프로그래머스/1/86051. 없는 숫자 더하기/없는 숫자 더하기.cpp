#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int a = 0;
    
    for(int i = 0; i < numbers.size(); i++){
        a += numbers[i];
    }
    return 45 - a;
}