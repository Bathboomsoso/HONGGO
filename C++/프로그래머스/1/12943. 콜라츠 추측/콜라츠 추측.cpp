#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int i = 0;
    long long num2 = num;
    while(i <= 500){
        while(num2 % 2 == 0){
            if(num2 == 1 && i <= 500){
                return i;
            }
            num2 /= 2;
            i++;
        }
        while(num2 % 2 != 0){
            if(num2 == 1 && i <= 500){
                return i;
            }
            num2 = (num2 * 3) + 1;
            i++;
        }
    }
    return -1;
}