#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool is_space(int s, int e, const vector<pair<int, int>>& r){
    for(auto p: r) if(p.first <= e && p.second >= s) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> result;
    for(int i = 0; i < n; i++){
        int s, d;
        cin >> s >> d;
        if(is_space(s, s + d - 1, result)) result.push_back({s, s + d - 1});
        else {
            if(is_space(1, d, result)) result.push_back({1, d});
            else {
                int best_x = INT_MAX;
                for(auto p: result) if(is_space(p.second + 1, p.second + d, result)) best_x = min(best_x, p.second + 1);
                result.push_back({best_x, best_x + d - 1});
            }
        }
    }
    for(auto p: result) cout << p.first << ' ' << p.second << '\n';
    return 0;
}