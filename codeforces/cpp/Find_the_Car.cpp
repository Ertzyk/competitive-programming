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
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> a(k + 1, 0), b(k + 1, 0), prefix_b(k + 1, 0);
        for(ll i = 1; i <= k; i++) cin >> a[i];
        for(ll i = 1; i <= k; i++) cin >> b[i];
        for(ll i = 1; i <= k; i++) prefix_b[i] = prefix_b[i - 1] + b[i];
        while(q--){
            ll d;
            cin >> d;
            ll j = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
            cout << ((j == k) ? b[k] : ((d - a[j])*(b[j + 1] - b[j])/(a[j + 1] - a[j]) + b[j])) << ' ';
        }
        cout << '\n';
    }
    return 0;
}