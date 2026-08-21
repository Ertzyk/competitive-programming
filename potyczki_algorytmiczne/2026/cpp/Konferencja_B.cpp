#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n1;
    cin >> k >> n1;
    vector<vector<int>> parent(k + 1);
    vector<vector<ll>> weights(k + 1);
    weights[1].resize(n1 + 1, 0);
    for(int i = 2; i <= k; i++){
        int ni;
        cin >> ni;
        parent[i].resize(ni + 1);
        weights[i].resize(ni + 1, 0);
        for(int j = 1; j <= ni; j++) cin >> parent[i][j];
    }
    for(int i = k; i >= 1; i--){
        for(int j = 1; j < weights[i].size(); j++){
            if(weights[i][j] == 0) weights[i][j] = 1;
            if(i > 1 && parent[i][j] > 0) weights[i - 1][parent[i][j]] += weights[i][j];
        }
    }
    ll max_p = 0;
    for(int i = 1; i <= k; ++i){
        ll suma_dnia = 0;
        for(int j = 1; j < weights[i].size(); j++) suma_dnia += weights[i][j];
        max_p = max(max_p, suma_dnia);
    }
    cout << max_p << '\n';
    return 0;
}