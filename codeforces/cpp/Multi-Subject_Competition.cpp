#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, max_len = 1;
    cin >> n >> m;
    vector<vector<int>> a(m + 1);
    for(int i = 0; i < n; i++){
        int s, r;
        cin >> s >> r;
        a[s].push_back(r);
    }
    for(int i = 1; i <= m; i++){
        sort(a[i].rbegin(), a[i].rend());
        max_len = max(max_len, (int)a[i].size());
    }
    vector<int> best(max_len);
    for(int i = 1; i <= m; i++){
        if(a[i].empty() || a[i][0] <= 0) continue;
        best[0] += a[i][0];
        for(int j = 1; j < a[i].size(); j++){
            a[i][j] += a[i][j - 1];
            if(a[i][j] <= 0) break;
            best[j] += a[i][j];
        }
    }
    cout << *max_element(best.begin(), best.end()) << '\n';
    return 0;
}