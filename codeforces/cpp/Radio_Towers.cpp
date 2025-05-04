#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll fast_exponentiation(ll a, ll b, ll m){
    ll result = 1;
    while(b > 0){
        if(b%2) {
            result *= a;
            result %= m;
        }
        a = a*a%m;
        b /= 2;
    }
    return result;
}

ll modular_inverse(ll a, ll m){
    return fast_exponentiation(a, m - 2, m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    ll odd = 1, even = 1;
    for(ll i = 2; i <= n; i++){
        if(i%2 == 0){
            dp[i] = odd;
            even += dp[i];
            even %= MOD;
        } else {
            dp[i] = even;
            odd += dp[i];
            odd %= MOD;
        }
    }
    cout << dp[n]*modular_inverse(fast_exponentiation(2, n, MOD), MOD)%MOD;
    return 0;
}