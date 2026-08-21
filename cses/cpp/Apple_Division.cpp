#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;

ll find_max_below(const vector<ll> &p, ll val, ll idx){
    if(idx >= p.size() || val == 0) return 0;
    ll M = find_max_below(p, val, idx + 1);
    if(val - p[idx] >= 0) M = max(M, find_max_below(p, val - p[idx], idx + 1) + p[idx]);
    return M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> p(n);
    for(ll &x: p) cin >> x;
    ll S = accumulate(p.begin(), p.end(), (ll)0);
    ll l = find_max_below(p, S/2, 0);
    cout << S - 2*l << '\n';
    return 0;
}