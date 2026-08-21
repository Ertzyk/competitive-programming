#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    ll l = a[n/2] + 1, r = a[n/2] + k, res = a[n/2];
    while(l <= r){
        ll m = l + (r - l)/2, d = 0;
        for(ll i = n/2; i < n; i++) d += max(m - a[i], (ll)0);
        if(d <= k){
            res = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << res << '\n';
    return 0;
}