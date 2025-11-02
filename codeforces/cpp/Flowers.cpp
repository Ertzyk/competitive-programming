#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t, k;
    cin >> t >> k;
    vector<ll> dp(100001), prefix_sum_dp(100002);
    dp[0] = 1;
    for(int i = 1; i <= 100000; i++) dp[i] = (dp[i - 1] + ((i >= k) ? dp[i - k] : 0))%MOD;
    for(int i = 1; i <= 100001; i++) prefix_sum_dp[i] = prefix_sum_dp[i - 1] + dp[i - 1];
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (prefix_sum_dp[b + 1] - prefix_sum_dp[a])%MOD << '\n';
    }
    return 0;
}