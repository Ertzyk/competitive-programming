#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    vector<pair<ll, ll>> edges(m);
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        edges[i].first = u;
        edges[i].second = v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n + 1);
    vector<ll> color(n + 1, -1);
    deque<ll> dq;
    dq.push_back(1);
    visited[1] = true;
    color[1] = 0;
    bool possible_2_coloring = true;
    while(!dq.empty()){
        ll node = dq.front();
        dq.pop_front();
        for(ll neighbor: graph[node]){
            if(visited[neighbor]){
                if(color[neighbor] == color[node]){
                    possible_2_coloring = false;
                    break;
                }
            } else {
                dq.push_back(neighbor);
                visited[neighbor] = true;
                color[neighbor] = 1 - color[node];
            }
        }
        if(!possible_2_coloring) break;
    }
    if(!possible_2_coloring){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(ll i = 0; i < m; i++) cout << color[edges[i].first];
        cout << '\n';
    }
    return 0;
}