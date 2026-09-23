#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<ll> h(n);
        for(ll &x: h) cin >> x;
        ll res = *min_element(h.begin(), h.end()), r = h[n - 1];
        ll l = res + 1;
        vector<ll> d(n, 0);
        for(ll i = 2; i < n; i++) d[i] = h[i]/3;
        while(l <= r){
            vector<ll> h_cp(h.begin(), h.end());
            ll m = (l + r)/2;
            bool flag = false;
            for(ll i = n - 1; i >= 2; i--){
                if(h_cp[i] < m){
                    r = m - 1;
                    flag = true;
                    break;
                }
                ll c = min((h_cp[i] - m)/3, d[i]);
                h_cp[i] -= 3*c;
                h_cp[i - 1] += c;
                h_cp[i - 2] += 2*c;
            }
            if(!flag){
                if(h_cp[0] >= m && h_cp[1] >= m){
                    res = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}