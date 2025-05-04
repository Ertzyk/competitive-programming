#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n + 1, false), visited2(n + 1, false);
    queue<pair<int, int>> q, q2;
    q.push({s, 0});
    visited[s] = true;
    vector<int> dist_s(n), dist_t(n);
    int st_dist;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first, depth = front.second;
        dist_s[depth]++;
        if(node == t) st_dist = depth;
        for(int neighbor: graph[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
            }
        }
    }
    q2.push({t, 0});
    visited2[t] = true;
    while(!q2.empty()){
        auto front = q2.front();
        q2.pop();
        int node = front.first, depth = front.second;
        dist_t[depth]++;
        for(int neighbor: graph[node]){
            if(!visited2[neighbor]){
                visited2[neighbor] = true;
                q2.push({neighbor, depth + 1});
            }
        }
    }
    vector<int> prefix_sum(st_dist - 1);
    int cur = 0;
    for(int i = 0; i < st_dist - 1; i++){
        cur += dist_s[i];
        prefix_sum[i] = cur;
    }
    int result = 0;
    for(int i = prefix_sum.size() - 1; i >= 0; i--) result += prefix_sum[i]*dist_t[prefix_sum.size() - 1 - i];
    cout << n*(n - 1)/2 - m - result;
    return 0;
}