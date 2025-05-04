#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll gcd(ll a, ll b){
    return ((b == 0) ? a : gcd(b, a%b));
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll biggest_non_divisor(ll x){
    int i = 2;
    while(true){
        if(x%i != 0) return i;
        i++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> min_multiple(38);
    ll cur = 1;
    for(ll i = 1; i < 38; i++){
        cur = lcm(cur, i);
        min_multiple[i] = cur;
    }
    // for(ll x: min_multiple) cout << x << ' ';
    vector<ll> checkpoint_results(38);
    checkpoint_results[1] = 2;
    for(ll i = 2; i < 38; i++) checkpoint_results[i] = (min_multiple[i]/min_multiple[i - 1]*checkpoint_results[i - 1] + 1)%MOD;
    // cout << '\n';
    // for(ll x: checkpoint_results) cout << x << ' ';
    int t;
    cin >> t;
    while(t--){
        ll n, result = 0;
        cin >> n;


        // ll result2 = 0;
        // for(int i = 1; i <= n; i++){
        //     result2 += biggest_non_divisor(i);
        // }
        // cout << result2%MOD << '\n';

        int pointer = 37;
        while(n > 0){
            result += n/min_multiple[pointer]*checkpoint_results[pointer];
            n %= min_multiple[pointer];
            pointer--;
            // cout << result << ' ' << n << ' ' << pointer << '\n';
        }
        cout << result%MOD << '\n';
    }
    return 0;
}