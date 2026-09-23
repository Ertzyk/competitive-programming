#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, res = 0;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));
    for(ll i = 1; i <= n; i++) dp[i][1] = 1;
    for(ll i = 2; i <= m + 1; i++) dp[1][i] = 1;
    for(ll i = 2; i <= n; i++){
        for(ll j = 2; j <= m + 1; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    for(ll i = 1; i <= n; i++){
        res += dp[i][m + 1]*dp[n - i + 1][m];
        res %= MOD;
    }
    cout << res << '\n';
    return 0;
}