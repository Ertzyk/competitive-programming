#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;

class DSU{
    private:
    ll components;
    vector<ll> parent, size;
    public:
    DSU(ll n){
        parent.resize(n);
        size.resize(n, 1);
        for(ll i = 0; i < n; i++) parent[i] = i;
        components = n;
    }
    ll find(ll v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(ll a, ll b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
        }
    }
    ll get_components(){
        return components;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n + m);
    for(ll i = 0; i < q; i++){
        ll r, c;
        cin >> r >> c;
        dsu.unite(r - 1, c + n - 1);
    }
    cout << dsu.get_components() - 1 << '\n';
    return 0;
}