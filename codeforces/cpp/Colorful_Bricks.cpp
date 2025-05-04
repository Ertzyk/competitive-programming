#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    for(int i = 1; i <= n; i++) dp[i][0] = m;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i - 1][j] + (m - 1)*dp[i - 1][j - 1])%MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}