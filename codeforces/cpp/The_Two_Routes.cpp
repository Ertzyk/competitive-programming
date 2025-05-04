#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
using vi = vector<int>;
using si = unordered_set<int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<si> road_network(n + 1), railway_network(n + 1);
    si normal_set;
    for(int i = 1; i <= n; i++) normal_set.insert(i);
    for(int i = 1; i <= n; i++) {
        road_network[i] = normal_set;
        road_network[i].erase(i);
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        railway_network[u].insert(v);
        railway_network[v].insert(u);
        road_network[u].erase(v);
        road_network[v].erase(u);
    }
    vector<bool> visited(n + 1, false);
    queue<vi> q;
    q.push({1, 0});
    visited[1] = true;
    if(railway_network[1].count(n)){
        while(!q.empty()){
            vi front = q.front();
            int city = front[0], depth = front[1];
            q.pop();
            if(city == n){
                cout << depth;
                return 0;
            }
            for(int neighbor: road_network[city]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        cout << -1;
    } else {
        while(!q.empty()){
            vi front = q.front();
            int city = front[0], depth = front[1];
            q.pop();
            if(city == n){
                cout << depth;
                return 0;
            }
            for(int neighbor: railway_network[city]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        cout << -1;
    }
    return 0;
}