#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> window(200019, 0), dp(200010, 0);
    window[9] = 1;
    ll s = 1;
    dp[0] = 1;
    for(int i = 0; i < 200009; i++){
        window[i + 9] += window[i];
        window[i + 9] %= MOD;
        window[i + 10] = window[i]%MOD;
        s += window[i];
        s %= MOD;
        dp[i + 1] = s;
    }
    while(t--){
        string n;
        int m;
        cin >> n >> m;
        ll result = 0;
        for(char ch: n) result += dp[m + ch - '0'];
        cout << result%MOD << '\n';
    }
    return 0;
}