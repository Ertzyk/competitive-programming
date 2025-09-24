#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> graph(2*n + 1);
    vector<ll> a(n + 1), degrees(2*n + 1, -1);
    for(ll i = 2; i <= n; i++) cin >> a[i];
    for(ll i = 2; i <= n; i++){
        if(i + a[i] > n) graph[0].push_back(i);
        else graph[i + a[i] + n].push_back(i);
        if(i - a[i] <= 0) graph[0].push_back(i + n);
        else if(i - a[i] > 1) graph[i - a[i]].push_back(i + n);
    }
    degrees[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(ll neighbor: graph[node]){
            degrees[neighbor] = degrees[node] + ((neighbor <= n) ? a[neighbor] : a[neighbor - n]);
            q.push(neighbor);
        }
    }
    for(ll i = n + 2; i <= 2*n; i++) cout << ((degrees[i] == -1) ? -1 : degrees[i] + i - n - 1) << '\n';
    return 0;
}