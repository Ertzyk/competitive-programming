#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
const long long MOD = 998244353;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll inverse(int n, int m){
    ll result, y;
    gcd(n, m, result, y);
    return (result+3*MOD)%MOD;
}

ll find_sum(ll goal, const vector<ll>& c, int pointer, ll cur){
    if(cur > goal) return 0;
    if(pointer == c.size()){
        if(cur == goal){
            return 1;
        } else {
            return 0;
        }
    }
    return find_sum(goal, c, pointer + 1, cur) + find_sum(goal, c, pointer + 1, cur + c[pointer]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> pre_inverse(500001);
    for(int i = 1; i < 500001; i++){
        pre_inverse[i] = inverse(i, MOD);
    }
    while(t--){
        vector<ll> c;
        for(int i = 0; i < 26; i++){
            ll x;
            cin >> x;
            if(x) c.push_back(x);
        }
        sort(c.rbegin(), c.rend());
        ll s = accumulate(c.begin(), c.end(), (ll)0), result = 1;
        if(s == 1){
            cout << "1\n";
            continue;
        }
        for(ll i = 2; i <= s/2; i++){
            result *= i;
            result %= MOD;
        }
        result *= result;
        result %= MOD;
        if(s%2){
            result *= s/2 + 1;
            result %= MOD;
        }
        for(ll x: c){
            for(int i = 2; i <= x; i++){
                result *= pre_inverse[i];
                result %= MOD;
            }
        }
        ll o = find_sum(s/2, c, 0, 0);
        cout << result*o%MOD << '\n';
    }
    return 0;
}