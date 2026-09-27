#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(ll d = 1; d <= n - 1; d++){
        for(ll l = 0; l < n - d; l++){
            dp[l][l + d] = min(dp[l + 1][l + d], dp[l][l + d - 1]) + a[l + d] - a[l];
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}