#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() <= 1){
        arr.pop_back();
        arr.push_back(-1);
        return arr;
    }
    
    auto fd = min_element(arr.begin(), arr.end());
    arr.erase(fd);
    
    return arr;
}