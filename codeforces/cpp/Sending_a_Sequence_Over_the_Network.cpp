#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> b(n);
        for(ll &x: b) cin >> x;
        map<ll, vector<ll>> mp;
        for(ll i = 0; i < n; i++){
            if(i - b[i] >= 0) mp[i].push_back(i - b[i]);
            if(i + b[i] < n) mp[i + b[i]].push_back(i);
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(ll i = 0; i < n; i++){
            for(ll v: mp[i]){
                if(dp[v]){
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        cout << (dp[n] ? "YES\n" : "NO\n");
    }
    return 0;
}