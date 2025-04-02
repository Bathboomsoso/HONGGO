#include <string>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int fn = friends.size();
    vector<vector<int>> giftc(fn, vector<int>(fn, 0)); // 벡터 선언
    vector<int> give(fn, 0), rece(fn, 0), giftsc(fn, 0), nm(fn, 0);
        
    auto get_index = [&](const string & name){
        for (int i = 0 ; i < fn ; i++){
            if (friends[i] == name) return i;
        }
        return -1;
    };

for (string &gift : gifts) {
    size_t space = gift.find(' '); 
    string giver = gift.substr(0, space); // 준사람
    string receiver = gift.substr(space + 1); // 받은사람
    int g_idx = get_index(giver), r_idx = get_index(receiver); //인덱스
    giftc[g_idx][r_idx]++; // 증가
    give[g_idx]++;
    rece[r_idx]++;
}

for (int i = 0; i < fn; i++){
    giftsc[i] = give[i] - rece[i];
}

for (int i = 0; i < fn; i++){
    for (int a = 0; a < fn; a++){
        if (i == a) continue;
            if (giftc[i][a] > giftc[a][i]){
                nm[i]++;
                } else if (giftc[i][a] == giftc[a][i] && giftsc[i] > giftsc[a]) {
                    nm[i]++;
                }
            }
        }
    

int mgift = 0;
for (int i = 0; i < fn; i++) {
    if(nm[i] > mgift){
        mgift = nm[i];
    }
}
return mgift;
}