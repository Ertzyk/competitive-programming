#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

struct SegmentTree{
    ll n;
    vector<ll> t;

    SegmentTree(ll k){
        n = k;
        t.resize(4*k);
    }

    void build(const vector<ll>& a){
        build(a, 1, 0, n - 1);
    }

    void update(ll pos, ll new_val){
        update(1, 0, n - 1, pos, new_val);
    }

    ll minimum(ll l, ll r){
        return minimum(1, 0, n - 1, l, r);
    }

    void build(const vector<ll>& a, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v + 1, tm + 1, tr);
            t[v] = min(t[2*v], t[2*v + 1]);
        }
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val){
        if(tl == tr){
            t[v] = new_val;
        } else {
            ll tm = (tl + tr)/2;
            if(pos <= tm) update(2*v, tl, tm, pos, new_val);
            else update(2*v + 1, tm + 1, tr, pos, new_val);
            t[v] = min(t[2*v], t[2*v + 1]);
        }
    }

    ll minimum(ll v, ll tl, ll tr, ll l, ll r){
        if(l <= tl && r >= tr) return t[v];
        if(l > tr || r < tl) return LLONG_MAX;
        ll tm = (tl + tr)/2;
        return min(minimum(2*v, tl, tm, l, r), minimum(2*v + 1, tm + 1, tr, l, r));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    SegmentTree segtree(n);
    segtree.build(a);
    while(q--){
        ll option;
        cin >> option;
        if(option == 1){
            ll k, u;
            cin >> k >> u;
            segtree.update(k - 1, u);
        } else {
            ll a, b;
            cin >> a >> b;
            cout << segtree.minimum(a - 1, b - 1) << '\n';
        }
    }
    return 0;
}