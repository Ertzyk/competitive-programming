#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, l, k;
    cin >> n >> l >> k;
    vector<ll> d(n + 1), a(n);
    for(ll i = 0; i < n; i++) cin >> d[i];
    for(ll &x: a) cin >> x;
    d[n] = l;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
    for(ll i = 0; i <= k; i++) dp[1][i] = d[1]*a[0];
    for(ll nn = 2; nn <= n; nn++){
        for(ll kk = 0; kk <= k; kk++){
            dp[nn][kk] = dp[nn - 1][kk] + (d[nn] - d[nn - 1])*a[nn - 1];
            ll i = 2;
            while(nn - i >= 0 && kk - i + 1 >= 0){
                dp[nn][kk] = min(dp[nn][kk], dp[nn - i][kk - i + 1] + (d[nn] - d[nn - i])*a[nn - i]);
                i++;
            }
        }
    }
    cout << dp[n][k] << '\n';
    return 0;
}