#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> distances(n + 1);
    for(int i = 1; i < n; i++){
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(i != a) graph[i].push_back(a);
    }
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first, depth = front.second;
        distances[node] = depth;
        for(int neighbor: graph[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << distances[i] << ' ';
    return 0;
}