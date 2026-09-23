#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> lpf(5000001, -1), dp(5000001, 0), pref_sum_dp(5000001, 0);
    for(ll i = 2; i <= 5000000; i++){
        if(lpf[i] == -1){
            lpf[i] = i;
            for(ll j = i*i; j <= 5000000; j += i){
                if(lpf[j] == -1) lpf[j] = i;
            }
        }
    }
    for(ll i = 2; i <= 5000000; i++) dp[i] = dp[i/lpf[i]] + 1;
    for(ll i = 2; i <= 5000000; i++) pref_sum_dp[i] = pref_sum_dp[i - 1] + dp[i];
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << pref_sum_dp[a] - pref_sum_dp[b] << '\n';
    }
    return 0;
}