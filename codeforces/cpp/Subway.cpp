#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n + 1);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    vector<int> parents(n + 1);
    pair<int, int> colision;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first, parent = front.second;
        parents[node] = parent;
        for(int neighbor: graph[node]) if(neighbor != parent){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else {
                colision.first = node;
                colision.second = neighbor;
            }
        }
    }
    int p = colision.first, r = colision.second;
    vector<int> path1, path2;
    do{
        path1.push_back(p);
        p = parents[p];
    } while(p != 0);
    do{
        path2.push_back(r);
        r = parents[r];
    } while(r != 0);
    int last = -1;
    while(path1.back() == path2.back()){
        last = path1.back();
        path1.pop_back();
        path2.pop_back();
    }
    unordered_set<int> cycle(path1.begin(), path1.end());
    for(int x: path2) cycle.insert(x);
    cycle.insert(last);
    vector<int> result(n + 1, -1);
    vector<bool> visited2(n + 1, false);
    for(int x: cycle){
        q.push({x, 0});
        visited2[x] = true;
    }
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first, depth = front.second;
        result[node] = depth;
        for(int neighbor: graph[node]) if(!visited2[neighbor]){
            visited2[neighbor] = true;
            q.push({neighbor, depth + 1});
        }
    }
    for(int i = 1; i <= n; i++) cout << result[i] << ' ';
    return 0;
}