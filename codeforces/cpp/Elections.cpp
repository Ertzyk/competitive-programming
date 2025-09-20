#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, result_max = 0;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
    vector<int> v_max;
    for(int i = 1; i <= m; i++) v_max.push_back(i);
    for(int i = 0; i < n - 1; i++){
        vector<pair<int, int>> diff(m);
        for(int j = 0; j < m; j++) diff[j] = {a[j][i] - a[j][n - 1], j + 1};
        sort(diff.rbegin(), diff.rend());
        int sm = 0, p = 0;
        while(sm >= 0 && p < m){
            sm += diff[p].first;
            p++;
        }
        p--;
        if(sm >= 0){
            result_max = m;
            v_max.clear();
        } else if(p > result_max){
            result_max = p;
            v_max.clear();
            for(int j = p; j < m; j++) v_max.push_back(diff[j].second);
        }
    }
    cout << m - result_max << '\n';
    for(int x: v_max) cout << x << ' ';
    cout << '\n';
    return 0;
}