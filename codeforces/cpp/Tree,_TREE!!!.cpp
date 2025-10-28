#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void dfs(int node, int parent, vector<vector<int>>& subtree_sizes, const vector<vector<int>>& graph, vector<int>& complete_size){
    for(int neighbor: graph[node]){
        if(neighbor != parent){
            dfs(neighbor, node, subtree_sizes, graph, complete_size);
            complete_size[node] += complete_size[neighbor];
            subtree_sizes[node].push_back(complete_size[neighbor]);
        }
    }
    complete_size[node]++;
    subtree_sizes[node].push_back(graph.size() - 1 - complete_size[node]);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> graph(n + 1), subtree_sizes(n + 1);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> complete_size(n + 1);
        dfs(1, 0, subtree_sizes, graph, complete_size);
        ll res = n;
        for(int i = 1; i <= n; i++){
            for(int x: subtree_sizes[i]){
                if(n - x >= k) res += x;
            }
        }
        cout << res << '\n';
    }
    return 0;
}