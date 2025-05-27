#include <vector>
#include <numeric>

using namespace std;

double solution(const std::vector<int> arr) {
    return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}