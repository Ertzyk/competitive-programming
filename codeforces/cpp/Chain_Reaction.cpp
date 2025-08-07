#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(auto &x: a) cin >> x.first >> x.second;
    sort(a.begin(), a.end());
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++){
        int k = lower_bound(a.begin(), a.end(), a[i].first - a[i].second, [](pair<int, int> p, int b){return p.first < b;}) - a.begin();
        dp[i + 1] = dp[k] + 1;
        result = max(dp[i + 1], result);
    }
    cout << n - result << '\n';
    return 0;
}