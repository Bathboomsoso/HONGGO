#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = 0 ;
    for(int i = 2 ; i <= n; i += 2)
    a += i;
    return a;
}