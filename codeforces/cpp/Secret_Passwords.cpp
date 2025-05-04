#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DSU{
    private:
    vector<int> parent, size;
    int components;
    public:
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        components = n;
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
        }
    }
    int count_components(){return components;}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    DSU dsu(26);
    unordered_set<int> seen;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size() - 1; j++){
            dsu.unite((int)s[j] - (int)'a' + 1, (int)s[j + 1] - (int)'a' + 1);
            seen.insert((int)s[j] - (int)'a' + 1);
        }
        seen.insert((int)s[s.size() - 1] - (int)'a' + 1);
    }
    cout << dsu.count_components() + seen.size() - 26;
    return 0;
}