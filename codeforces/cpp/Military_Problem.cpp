#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void dfs(int node, const vector<vector<int>>& tree, vector<int>& subtree_size, vector<int>& order){
    order.push_back(node);
    for(int child: tree[node]){
        dfs(child, tree, subtree_size, order);
        subtree_size[node] += subtree_size[child];
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n + 1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        tree[p].push_back(i);
    }
    vector<int> subtree_size(n + 1, 1), order, order_minus1(n + 1);
    dfs(1, tree, subtree_size, order);
    for(int i = 0; i < n; i++) order_minus1[order[i]] = i;
    while(q--){
        int u, k;
        cin >> u >> k;
        cout << ((k <= subtree_size[u]) ? order[order_minus1[u] + k - 1] : -1) << '\n';
    }
    return 0;
}