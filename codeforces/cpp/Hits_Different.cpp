#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> dp(1000001, 0), row(1000001, 0);
    unordered_set<ll> st;
    dp[1] = 1;
    ll i = 1, cnt = 1, t;
    while(cnt <= 1000000){
        for(ll j = 0; j < i; j++){
            row[cnt] = i;
            cnt++;
            if(cnt > 1000000) break;
        }
        if(cnt > 1000000) break;
        i++;
        st.insert(cnt);
    }
    for(ll j = 2; j <= 1000000; j++){
        if(st.count(j)){
            dp[j] = j*j + dp[j - row[j] + 1];
        } else if(st.count(j + 1)){
            dp[j] = j*j + dp[j - row[j]];
        } else {
            dp[j] = j*j - dp[j - 2*(row[j] - 1)] + dp[j - row[j] + 1] + dp[j - row[j]];
        }
    }
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}