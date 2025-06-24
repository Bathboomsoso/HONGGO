#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max1 = 0;
    int max2 = 0;
    
    for(int i = 0; i < sizes.size(); ++i)
    {
        sort(sizes[i].begin(), sizes[i].end());
        cout << sizes[i][0] << " " << sizes[i][1] << endl;
    }
    
    for(int i = 0; i < sizes.size(); ++i)
    {
        if(sizes[i][0] > max1){
            max1 = sizes[i][0];
        }
        if(sizes[i][1] > max2){
            max2 = sizes[i][1];
        }
    }
    cout << max1 << " " << max2 << endl;
    
    
    
    return max1 * max2;
}