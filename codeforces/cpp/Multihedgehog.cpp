#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<int> depth(n + 1, 0);
    for(int i = 1; i <= n; i++) if(graph[i].size() == 1){
        q.push(i);
        visited[i] = true;
    }
    int last = -1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        last = node;
        for(int neighbor: graph[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                depth[neighbor] = depth[node] + 1;
                q.push(neighbor);
            }
        }
    }
    if(depth[last] != k || graph[last].size() < 3){
        cout << "No\n";
        return 0;
    }
    queue<pair<int, int>> q2;
    q2.push({last, 0});
    fill(visited.begin(), visited.end(), false);
    visited[last] = true;
    while(!q2.empty()){
        auto [node, depth2] = q2.front();
        q2.pop();
        if(depth2 + depth[node] != k || (depth[node] != 0 && depth[node] != k && graph[node].size() < 4) ||
        (depth[node] == 0 && graph[node].size() != 1)){
            cout << "No\n";
            return 0;
        }
        for(int neighbor: graph[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q2.push({neighbor, depth2 + 1});
            }
        }
    }
    cout << "Yes\n";
    return 0;
}