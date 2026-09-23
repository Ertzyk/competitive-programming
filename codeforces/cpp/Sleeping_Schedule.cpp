#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, h, l, r, p = 0;
    cin >> n >> h >> l >> r;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(h));
    dp[0][0] = 0;
    for(ll i = 1; i < h; i++) dp[0][i] = -1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < h; j++){
            ll M = max(dp[i - 1][(j + h - a[i - 1])%h], dp[i - 1][(j + h - a[i - 1] + 1)%h]);
            if(M == -1) dp[i][j] = -1;
            else {
                if(l <= j && j <= r){
                    dp[i][j] = M + 1;
                } else {
                    dp[i][j] = M;
                }
            }
        }
    }
    for(ll i = 0; i < h; i++) p = max(p, dp[n][i]);
    cout << p << '\n';
    return 0;
}