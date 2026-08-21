#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void dfs(ll node, const vector<vector<ll>> &graph, vector<ll> &subordinates){
    for(ll child: graph[node]){
        dfs(child, graph, subordinates);
        subordinates[node] += subordinates[child] + 1;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> graph(n + 1);
    vector<ll> subordinates(n + 1, 0);
    for(ll i = 2; i <= n; i++){
        ll s;
        cin >> s;
        graph[s].push_back(i);
    }
    dfs(1, graph, subordinates);
    for(ll i = 1; i <= n; i++) cout << subordinates[i] << " \n"[i == n];
    return 0;
}