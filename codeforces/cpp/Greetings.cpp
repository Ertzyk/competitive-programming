#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

struct Segment {
    ll a, b;
    bool operator<(const Segment &other) const {
        if(b != other.b) return b < other.b;
        return a > other.a;
    }
};

struct SegmentTree{
    ll n;
    vector<ll> t;

    SegmentTree(ll k){
        n = k;
        t.assign(4*k, 0);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll add){
        if(tl == tr){
            t[v] += add;
        } else {
            ll tm = (tl + tr)/2;
            if(pos <= tm) update(2*v, tl, tm, pos, add);
            else update(2*v + 1, tm + 1, tr, pos, add);
            t[v] = t[2*v] + t[2*v + 1];
        }
    }

    ll sum(ll v, ll tl, ll tr, ll l, ll r){
        if(l <= tl && r >= tr) return t[v];
        if(l > tr || r < tl) return 0;
        ll tm = (tl + tr)/2;
        return sum(2*v, tl, tm, l, r) + sum(2*v + 1, tm + 1, tr, l, r);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, result = 0, k = 0;
        cin >> n;
        vector<Segment> segments(n);
        map<ll, ll> mp;
        for(ll i = 0; i < n; i++){
            cin >> segments[i].a >> segments[i].b;
            mp[segments[i].a] = 0;
            mp[segments[i].b] = 0;
        }
        sort(segments.begin(), segments.end());
        for(auto pr: mp){
            mp[pr.first] = k;
            k++;
        }
        for(ll i = 0; i < n; i++){
            segments[i].a = mp[segments[i].a];
            segments[i].b = mp[segments[i].b];
        }
        SegmentTree segtree(2*n);
        for(ll i = 0; i < n; i++){
            result += segtree.sum(1, 0, 2*n - 1, segments[i].a, segments[i].b);
            segtree.update(1, 0, 2*n - 1, segments[i].a, 1);
        }
        cout << result << '\n';
    }
    return 0;
}