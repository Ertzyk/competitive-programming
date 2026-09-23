#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct SegmentTree {
    ll n;
    vector<ll> t;
    vector<bool> marked;

    SegmentTree(ll k){
        n = k;
        t.resize(4*k);
        marked.resize(4*k);
    }

    void build(ll v, ll tl, ll tr){
        if(tl == tr){
            t[v] = 0;
            marked[v] = true;
        } else {
            ll tm = (tl + tr)/2;
            build(2*v, tl, tm);
            build(2*v + 1, tm + 1, tr);
            t[v] = 0;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, ll new_val){
        if(l > tr || r < tl) return;
        if(l <= tl && r >= tr){
            t[v] = new_val;
            marked[v] = true;
        } else {
            push(v);
            ll tm = (tl + tr)/2;
            update(2*v, tl, tm, l, r, new_val);
            update(2*v + 1, tm + 1, tr, l, r, new_val);
        }
    }

    void push(ll v){
        if(marked[v]){
            t[2*v] = t[2*v + 1] = t[v];
            marked[2*v] = marked[2*v + 1] = true;
            marked[v] = false;
        }
    }

    ll get(ll v, ll tl, ll tr, ll pos){
        if(tl == tr){
            return t[v];
        } else {
            if(marked[v]) return t[v];
            ll tm = (tl + tr)/2;
            if(pos <= tm) return get(2*v, tl, tm, pos);
            return get(2*v + 1, tm + 1, tr, pos);
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> l(m), r(m), x(m);
    for(ll i = 0; i < m; i++) cin >> l[i] >> r[i] >> x[i];
    SegmentTree segtree(n);
    segtree.build(1, 0, n - 1);
    for(ll i = m - 1; i >= 0; i--){
        segtree.update(1, 0, n - 1, l[i] - 1, x[i] - 2, x[i]);
        segtree.update(1, 0, n - 1, x[i], r[i] - 1, x[i]);
    }
    for(ll i = 0; i < n; i++) cout << segtree.get(1, 0, n - 1, i) << " \n"[i == n - 1];
    return 0;
}