#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<vector<int>> a(k + 1);
    for(int i = 1; i <= n; i++){
        int good_type;
        cin >> good_type;
        a[good_type].push_back(i);
    }
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<priority_queue<int, vector<int>, greater<int>>> dist_to_goods(n + 1);
    for(int good_type = 1; good_type <= k; good_type++){
        vector<bool> visited(n + 1, false);
        queue<vector<int>> q;
        for(int x: a[good_type]){
            q.push({x, 0});
            visited[x] = true;
        }
        while(!q.empty()){
            vector<int> front = q.front();
            q.pop();
            int town = front[0], depth = front[1];
            dist_to_goods[town].push(depth);
            for(int neighbor: graph[town]){
                if(!visited[neighbor]){
                    q.push({neighbor, depth + 1});
                    visited[neighbor] = true;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 0; j < s; j++){
            sum += dist_to_goods[i].top();
            dist_to_goods[i].pop();
        }
        cout << sum << ' ';
    }
    return 0;
}