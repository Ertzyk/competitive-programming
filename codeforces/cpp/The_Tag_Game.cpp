#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int par, vector<int> &parent, vector<int> &h, const vector<vector<int>> &tree){
    parent[node] = par;
    for(int neighbor: tree[node]) if(neighbor != par){
        dfs(neighbor, node, parent, h, tree);
        h[node] = max(h[node], h[neighbor] + 1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> parent(n + 1), h(n + 1), x_path;
    dfs(1, 0, parent, h, tree);
    int p = x, ans = 0;
    x_path.reserve(n);
    while(p != 1){
        x_path.push_back(p);
        p = parent[p];
    }
    for(int i = 0; i <= (x_path.size() - 1)/2; i++) ans = max(ans, h[x_path[i]] + (int)x_path.size() - i);
    cout << 2*ans << '\n';
    return 0;
}