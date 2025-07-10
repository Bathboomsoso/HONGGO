#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    int PaintedLast= 0;

    for (int Sec : section) {
        if (Sec > PaintedLast) {
            answer++;
            PaintedLast = Sec + m - 1; 
        }
    }
    return answer;
}