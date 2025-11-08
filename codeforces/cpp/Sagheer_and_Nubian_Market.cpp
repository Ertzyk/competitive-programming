#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, S;
    cin >> n >> S;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    ll l = 0, r = n, k = 0, T = 0;
    while(l <= r){
        ll m = (l + r)/2;
        vector<ll> b(n);
        for(ll i = 0; i < n; i++) b[i] = a[i] + (i + 1)*m;
        sort(b.begin(), b.end());
        ll s = accumulate(b.begin(), b.begin() + m, (ll)0);
        if(s <= S){
            l = m + 1;
            k = m;
            T = s;
        } else r = m - 1;
    }
    cout << k << ' ' << T << '\n';
    return 0;
}