#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> w(n), d(n, -1), a;
        for(ll &x: w) cin >> x;
        for(int i = 0; i < n - 1; i++){
            ll u, v;
            cin >> u >> v;
            d[u - 1]++;
            d[v - 1]++;
        }
        ll res = accumulate(w.begin(), w.end(), (ll)0);
        cout << res << ' ';
        a.reserve(n + 1);
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < d[i]; j++){
                a.push_back(w[i]);
            }
        }
        sort(a.rbegin(), a.rend());
        for(ll x: a){
            res += x;
            cout << res << ' ';
        }
        cout << '\n';
    }
    return 0;
}