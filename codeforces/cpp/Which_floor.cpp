#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> kf(m);
    for(auto &p: kf) cin >> p.first >> p.second;
    vector<int> poss;
    for(int i = 1; i <= 100; i++){
        bool good = true;
        for(int j = 0; j < m; j++){
            if(ceil((float)kf[j].first/(float)i) != kf[j].second){
                good = false;
                break;
            }
        }
        if(good) poss.push_back(i);
    }
    if(ceil((float)n/(float)poss.front()) == ceil((float)n/(float)poss.back())) cout << ceil((float)n/(float)poss.front()) << '\n';
    else cout << "-1\n";
    return 0;
}