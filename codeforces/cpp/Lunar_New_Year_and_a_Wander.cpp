#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<bool> visited(n + 1, false);
    min_heap.push(1);
    visited[1] = true;
    while(!min_heap.empty()){
        int x = min_heap.top();
        min_heap.pop();
        for(int y: graph[x]) if(!visited[y]){
            min_heap.push(y);
            visited[y] = true;
        }
        cout << x << ' ';
    }
    return 0;
}