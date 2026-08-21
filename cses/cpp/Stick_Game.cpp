#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> p(k);
    for(ll &x: p) cin >> x;
    vector<char> dp(n + 1);
    dp[0] = 'L';
    for(ll i = 1; i <= n; i++){
        bool flag = false;
        for(ll j: p) if(i - j >= 0 && dp[i - j] == 'L'){
            dp[i] = 'W';
            flag = true;
            break;
        }
        if(!flag) dp[i] = 'L';
        cout << dp[i];
    }
    cout << '\n';
    return 0;
}