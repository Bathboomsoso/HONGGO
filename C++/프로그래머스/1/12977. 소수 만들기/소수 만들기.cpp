#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0; 
    int n = nums.size(); 

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int sum = nums[i] + nums[j] + nums[k];
                bool is_sosu = true;
                if (sum < 2) {
                    is_sosu = false;
                } else {
                    for (int a = 2; a * a <= sum; ++a) {
                        if (sum % a == 0) {
                            is_sosu = false;
                            break;
                        }
                    }
                }
                if (is_sosu) {
                    answer++;
                }
            }
        }
    }
    return answer;
}