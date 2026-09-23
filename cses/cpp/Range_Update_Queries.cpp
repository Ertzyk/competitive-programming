#include <iostream>
#include <vector>
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

    void update(ll l, ll r, ll add){
        update(1, 0, n - 1, l, r, add);
    }

    ll get(ll pos){
        return get(1, 0, n - 1, pos);
    }

    void build(const vector<ll>& a, ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v + 1, tm + 1, tr);
            t[v] = 0;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
        if(l > tr || r < tl) return;
        if(l <= tl && r >= tr){
            t[v] += add;
            return;
        }
        ll tm = (tl + tr)/2;
        update(2*v, tl, tm, l, r, add);
        update(2*v + 1, tm + 1, tr, l, r, add);
    }

    ll get(ll v, ll tl, ll tr, ll pos){
        if(tl == tr) return t[v];
        ll tm = (tl + tr)/2;
        if(pos <= tm) return get(2*v, tl, tm, pos) + t[v];
        return get(2*v + 1, tm + 1, tr, pos) + t[v];
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
            ll a, b, u;
            cin >> a >> b >> u;
            segtree.update(a - 1, b - 1, u);
        } else {
            ll k;
            cin >> k;
            cout << segtree.get(k - 1) << '\n';
        }
    }
    return 0;
}