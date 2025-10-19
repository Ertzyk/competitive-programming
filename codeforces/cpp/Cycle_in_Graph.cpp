#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, cur = 1, min_idx = n;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> path, idx(n + 1, -1);
    vector<bool> visited(n + 1, false);
    while(true){
        path.push_back(cur);
        idx[cur] = path.size() - 1;
        visited[cur] = true;
        bool found = false;
        for(int neighbor: graph[cur]){
            if(!visited[neighbor]){
                cur = neighbor;
                found = true;
                break;
            }
        }
        if(!found) break;
    }
    for(int neighbor: graph[path.back()]) min_idx = min(min_idx, idx[neighbor]);
    cout << path.size() - min_idx << '\n';
    for(int i = min_idx; i < path.size(); i++) cout << path[i] << " \n"[i == path.size() - 1];
    return 0;
}