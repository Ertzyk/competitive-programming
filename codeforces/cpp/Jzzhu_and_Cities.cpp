#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k, result = 0;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    vector<ll> train_routes(n + 1, -1);
    for(int i = 0; i < m; i++){
        ll u, v, x;
        cin >> u >> v >> x;
        graph[u].push_back({v, x});
        graph[v].push_back({u, x});
    }
    for(int i = 0; i < k; i++){
        ll s, y;
        cin >> s >> y;
        if(train_routes[s] == -1) train_routes[s] = y;
        else{
            result++;
            train_routes[s] = min(train_routes[s], y);
        }
    }
    vector<ll> d;
    d.assign(n + 1, LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    d[1] = 0;
    while(!pq.empty()){
        auto [dv, v] = pq.top();
        pq.pop();
        if(dv > d[v]) continue;
        for(auto [to, w]: graph[v]) if(d[v] + w < d[to]){
            d[to] = d[v] + w;
            pq.push({d[to], to});
        }
    }
    for(int i = 2; i <= n; i++) if(train_routes[i] != -1 && train_routes[i] >= d[i]) result++;
    cout << result << '\n';
    return 0;
}