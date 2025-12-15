#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void dfs_size(ll node, ll parent, const vector<vector<ll>> &tree, vector<ll> &len){
    len[node]++;
    for(ll neighbor: tree[node]) if(neighbor != parent){
        dfs_size(neighbor, node, tree, len);
        len[node] += len[neighbor];
    }
    return;
}

ll dfs_solve(ll node, ll parent, const vector<vector<ll>> &tree, const vector<ll> &len){
    ll res = 0;
    for(ll neighbor: tree[node]) if(neighbor != parent){
        res += dfs_solve(neighbor, node, tree, len);
        if(len[neighbor]%2 == 0) res++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> tree(n + 1);
    for(ll i = 0; i < n - 1; i++){
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    if(n%2){
        cout << "-1\n";
        return 0;
    }
    vector<ll> len(n + 1, 0);
    dfs_size(1, 0, tree, len);
    cout << dfs_solve(1, 0, tree, len) << '\n';
    return 0;
}