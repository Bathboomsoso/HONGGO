#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    if(angle <= 90)
    {
        return angle < 90 ? 1 : 2;
    }

    else
    {
        return angle < 180 ? 3 : 4;
    }
}