#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> colors(n + 1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int max_degree = 0;
    for(int i = 1; i <= n; i++) if(graph[i].size() > max_degree) max_degree = graph[i].size();
    colors[1] = 1;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()){
        auto front = q.front();
        int node = front.first, parent_color = front.second, cur_color = 1;
        q.pop();
        while(cur_color == colors[node] || cur_color == parent_color) cur_color++;
        for(int neighbor: graph[node]){
            if(colors[neighbor] == 0){
                colors[neighbor] = cur_color;
                do cur_color++; while(cur_color == colors[node] || cur_color == parent_color);
                q.push({neighbor, colors[node]});
            }
        }
    }
    cout << max_degree + 1 << '\n';
    for(int i = 1; i <= n; i++) cout << colors[i] << ' ';
    return 0;
}