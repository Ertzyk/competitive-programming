#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
const long long MOD = 998244353;

ll find_sum(ll goal, const vector<ll>& c, int pointer, ll cur){
    if(cur > goal) return 0;
    if(pointer == c.size()) return ((cur == goal) ? 1 : 0);
    return find_sum(goal, c, pointer + 1, cur) + find_sum(goal, c, pointer + 1, cur + c[pointer]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> factorial(250001), pre_inverse(500001), pre_pre_inverse(500001);
    factorial[0] = 1;
    for(ll i = 1; i <= 250000; i++) factorial[i] = i*factorial[i - 1]%MOD;
    pre_inverse[1] = 1;
    for(ll i = 2; i <= 500000; i++) pre_inverse[i] = MOD - MOD/i*pre_inverse[MOD%i]%MOD;
    pre_pre_inverse[1] = 1;
    for(ll i = 2; i <= 500000; i++) pre_pre_inverse[i] = pre_pre_inverse[i - 1]*pre_inverse[i]%MOD;
    while(t--){
        vector<ll> c;
        for(int i = 0; i < 26; i++){
            ll x;
            cin >> x;
            if(x) c.push_back(x);
        }
        sort(c.rbegin(), c.rend());
        ll s = accumulate(c.begin(), c.end(), (ll)0);
        if(s == 1){
            cout << "1\n";
            continue;
        }
        ll result = factorial[s/2]*factorial[s/2]%MOD;
        if(s%2){
            result *= s/2 + 1;
            result %= MOD;
        }
        for(ll x: c){
            result *= pre_pre_inverse[x];
            result %= MOD;
        }
        cout << result*find_sum(s/2, c, 0, 0)%MOD << '\n';
    }
    return 0;
}