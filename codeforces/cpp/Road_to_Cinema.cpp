#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<pair<ll, ll>> cars(n);
    for(auto &pr: cars) cin >> pr.first >> pr.second;
    vector<ll> g(k), h(k + 1);
    for(ll &x: g) cin >> x;
    if(s > t){
        cout << "-1\n";
        return 0;
    }
    sort(g.begin(), g.end());
    for(ll i = 0; i < k - 1; i++) h[i] = g[i + 1] - g[i];
    h[k - 1] = g[0];
    h[k] = s - g[k - 1];
    ll M = *max_element(h.begin(), h.end());
    ll l = M, r = 2*M, v = 2*M;
    while(l <= r){
        ll m = (l + r)/2, time = 0;
        for(ll d: h) time += ((2*d <= m) ? d : 3*d - m);
        if(time <= t){
            v = m;
            r = m - 1;
        } else l = m + 1;
    }
    ll min_cost = LLONG_MAX;
    for(auto pr: cars) if(pr.second >= v) min_cost = min(min_cost, pr.first);
    cout << ((min_cost == LLONG_MAX) ? -1 : min_cost) << '\n';
    return 0;
}