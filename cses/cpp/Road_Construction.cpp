#include <iostream>
#include <vector>
using namespace std;

class DSU{
    private:
    vector<int> parent, size;
    int components, largest_component;
    public:
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        components = n;
        largest_component = 1;
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
            largest_component = max(largest_component, size[a]);
        }
    }
    int get_components(){
        return components;
    }
    int get_largest_component(){
        return largest_component;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while(m--){
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
        cout << dsu.get_components() << ' ' << dsu.get_largest_component() << '\n';
    }
    return 0;
}