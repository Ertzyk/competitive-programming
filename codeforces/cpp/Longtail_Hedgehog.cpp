#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> max_road(n + 1, 1);
    for(int node = 2; node <= n; node++){
        for(int neighbor: graph[node]) if(neighbor < node) max_road[node] = max(max_road[node], max_road[neighbor] + 1);
    }
    ll result = 0;
    for(int i = 1; i <= n; i++) result = max(result, (ll)max_road[i]*(ll)graph[i].size());
    cout << result;
    return 0;
}