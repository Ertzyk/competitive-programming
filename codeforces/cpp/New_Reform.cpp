#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, result = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            queue<pair<int, int>> q;
            q.push({i, 0});
            bool cycle = false;
            while(!q.empty()){
                auto front = q.front();
                q.pop();
                int node = front.first, parent = front.second;
                for(int neighbor: graph[node]) if(neighbor != parent){
                    if(visited[neighbor]) cycle = true;
                    else{
                        visited[neighbor] = true;
                        q.push({neighbor, node});
                    }
                }
            }
            if(!cycle) result++;
        }
    }
    cout << result;
    return 0;
}