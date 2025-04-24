#include <vector>
#include <numeric>

double solution(const std::vector<int> arr) {
    return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}