#include <string>
#include <vector>

using namespace std;

std::string solution(int num) {
    return (num & 1) ? "Odd" : "Even";
}