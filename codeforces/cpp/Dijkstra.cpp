#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        if(a == b) continue;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    vector<ll> d, p;
    d.assign(n + 1, LLONG_MAX);
    p.assign(n + 1, -1);
    d[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll v = pq.top().second, dv = pq.top().first;
        pq.pop();
        if(dv > d[v]) continue;
        for(auto edge: graph[v]){
            if(d[v] + edge.second < d[edge.first]){
                d[edge.first] = d[v] + edge.second;
                p[edge.first] = v;
                pq.push({d[edge.first], edge.first});
            }
        }
    }
    if(p[n] == -1){
        cout << "-1\n";
        return 0;
    }
    vector<ll> path;
    for(ll v = n; v != -1; v = p[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    for(ll x: path) cout << x << ' ';
    cout << '\n';
    return 0;
}