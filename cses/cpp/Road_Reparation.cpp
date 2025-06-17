#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge& other){
        return w < other.w;
    }
};

class DSU {
    private:
    vector<int> parent, size;
    int components;
    public:
    DSU(int n){
        components = n;
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        size.resize(n + 1, 1);
    }
    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[b] > size[a]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
        }
    }
    int get_components(){
        return components;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(auto &e: edges) cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll cost = 0;
    for(const auto &e: edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            dsu.unite(e.u, e.v);
            cost += e.w;
        }
    }
    if(dsu.get_components() == 1) cout << cost << '\n';
    else cout << "IMPOSSIBLE\n";
    return 0;
}