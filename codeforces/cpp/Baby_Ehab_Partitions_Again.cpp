#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    ll g = a[0];
    for(ll i = 1; i < n; i++) g = gcd(g, a[i]);
    for(ll i = 0; i < n; i++) a[i] /= g;
    ll S = accumulate(a.begin(), a.end(), (ll)0);
    if(S%2 == 1){
        cout << "0\n";
        return 0;
    }
    bitset<100001> dp;
    dp[0] = 1;
    for(ll x: a) dp |= (dp << x);
    if(dp[S/2]){
        cout << "1\n";
        for(ll i = 0; i < n; i++){
            if((a[i]&1) == 1){
                cout << i + 1 << '\n';
                break;
            }
        }
    } else {
        cout << "0\n";
    }
    return 0;
}