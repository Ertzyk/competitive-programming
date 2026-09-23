#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> k >> m;
    vector<ll> p(n), pref_sum(n + 1, 0);
    for(ll &x: p) cin >> x;
    for(ll i = 1; i <= n; i++){
        pref_sum[i] = pref_sum[i - 1] + p[i - 1];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for(ll i = k; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(i < j*k) dp[i][j] = 0;
            else dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + pref_sum[i] - pref_sum[i - k]);
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}