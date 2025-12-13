#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, c, d;
        cin >> n >> c >> d;
        vector<ll> a(n), prefix_a(n + 1, 0);
        for(ll &x: a) cin >> x;
        sort(a.rbegin(), a.rend());
        for(ll i = 1; i <= n; i++) prefix_a[i] = prefix_a[i - 1] + a[i - 1];
        ll res = -1, l = 0, r = d;
        while(l <= r){
            ll m = (l + r)/2;
            ll days = (c - 1)/prefix_a[min(m + 1, n)]*(m + 1);
            auto it = lower_bound(prefix_a.begin(), prefix_a.end(), (c - 1)%prefix_a[min(m + 1, n)] + 1);
            days += (ll)(it - prefix_a.begin());
            if(days <= d){
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        cout << ((res == -1) ? "Impossible" : ((res == d) ? "Infinity" : to_string(res))) << '\n';
    }
    return 0;
}