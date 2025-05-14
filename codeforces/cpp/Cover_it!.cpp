#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        unordered_set<int> blue, red;
        vector<bool> visited(n + 1);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        blue.insert(1);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neighbor: graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                    if(blue.count(node)) red.insert(neighbor);
                    else blue.insert(neighbor);
                }
            }
        }
        if(blue.size() <= n/2){
            cout << blue.size() << '\n';
            for(int x: blue) cout << x << ' ';
        } else {
            cout << red.size() << '\n';
            for(int x: red) cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}