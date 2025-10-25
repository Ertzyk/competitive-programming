#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= i; k++){
            if(dp[i - 1][k - 1] == -1) dp[i][k] = -1;
            else if(dp[i - 1][k] == -1){
                dp[i][k] = dp[i - 1][k - 1] + a[i - 1];
                if(dp[i][k] < 0) dp[i][k] = -1;
            } else dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - 1] + a[i - 1]);
        }
    }
    for(int i = n; i >= 0; i--) if(dp[n][i] != -1){
        cout << i << '\n';
        break;
    }
    return 0;
}