#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

struct SegmentTree {
    ll n;
    vector<ll> t;

    SegmentTree(ll k){
        n = k;
        t.assign(4*k, 0);
    }

    void build(const vector<ll>& a, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v + 1, tm + 1, tr);
            t[v] = gcd(t[2*v], t[2*v + 1]);
        }
    }

    ll get(ll v, ll tl, ll tr, ll l, ll r){
        if(l > tr || r < tl) return 0;
        if(l <= tl && r >= tr) return t[v];
        ll tm = (tl + tr)/2;
        return gcd(get(2*v, tl, tm, l, r), get(2*v + 1, tm + 1, tr, l, r));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    map<ll, vector<ll>> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    SegmentTree segtree(n);
    segtree.build(a, 1, 0, n - 1);
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll g = segtree.get(1, 0, n - 1, l - 1, r - 1);
        cout << r - l + 1 - (upper_bound(mp[g].begin(), mp[g].end(), r - 1) - lower_bound(mp[g].begin(), mp[g].end(), l - 1)) << '\n';
    }
    return 0;
}