#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> maxes;
        int cur_max = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                int x;
                cin >> x;
                if(x > cur_max){
                    cur_max = x;
                    maxes.clear();
                    maxes.push_back({r, c});
                } else if(x == cur_max) maxes.push_back({r, c});
            }
        }
        if(maxes.size() <= 2){
            cout << cur_max - 1 << '\n';
            continue;
        }
        auto p1 = maxes[0], p2 = maxes[1];
        int mchr = -1, mchc = -1, type = 0;
        bool output = false;
        if(p1.first == p2.first){
            mchr = p1.first;
            for(int i = 2; i < maxes.size(); i++){
                if(maxes[i].first != mchr){
                    if(mchc == -1) mchc = maxes[i].second;
                    else if(mchc != maxes[i].second){
                        cout << cur_max << '\n';
                        output = true;
                        break;
                    }
                }
            }
        } else if(p1.second == p2.second){
            mchc = p2.second;
            for(int i = 2; i < maxes.size(); i++){
                if(maxes[i].second != mchc){
                    if(mchr == -1) mchr = maxes[i].first;
                    else if(mchr != maxes[i].first){
                        cout << cur_max << '\n';
                        output = true;
                        break;
                    }
                }
            }
        } else {
            pair<int, int> candidate1, candidate2;
            candidate1 = {p1.first, p2.second};
            candidate2 = {p2.first, p1.second};
            bool can1 = true, can2 = true;
            for(int i = 2; i < maxes.size(); i++){
                if(can1 && candidate1.first != maxes[i].first && candidate1.second != maxes[i].second) can1 = false;
                if(can2 && candidate2.first != maxes[i].first && candidate2.second != maxes[i].second) can2 = false;
            }
            if(can1 || can2) cout << cur_max - 1 << '\n';
            else cout << cur_max << '\n';
            output = true;
        }
        if(!output) cout << cur_max - 1 << '\n';
    }
    return 0;
}