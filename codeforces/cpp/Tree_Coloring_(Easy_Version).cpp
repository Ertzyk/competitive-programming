#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<ll>> tree(n + 1);
        for(ll i = 0; i < n - 1; i++){
            ll u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        queue<pair<ll, ll>> q;
        vector<vector<ll>> depths(n);
        vector<bool> visited(n + 1, false);
        q.push({1, 0});
        visited[1] = true;
        depths[0].push_back(1);
        while(!q.empty()){
            auto front = q.front();
            ll node = front.first;
            ll dep = front.second;
            q.pop();
            for(ll neighbor: tree[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push({neighbor, dep + 1});
                    depths[dep + 1].push_back(neighbor);
                }
            }
        }
        ll M = 0;
        for(auto ar: depths) M = max(M, (ll)ar.size());
        if(M == 1){
            cout << 2 << '\n';
            continue;
        }
        bool add_one = false;
        for(ll i = 1; i < n; i++){
            if(depths[i].size() == M){
                for(ll x: depths[i - 1]){
                    if(tree[x].size() - ((i == 1) ? 0 : 1) == M){
                        add_one = true;
                        break;
                    }
                }
            }
            if(add_one) break;
        }
        cout << M + ((add_one) ? 1 : 0) << '\n';
    }
    return 0;
}