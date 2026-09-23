#include <iostream>
#include <vector>
#include <deque>
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
        if(tree[1].size() == 1){
            cout << n - 2 << '\n';
            continue;
        }
        deque<ll> dq;
        dq.push_back(1);
        vector<bool> visited(n + 1, false);
        vector<ll> depth(n + 1, 1);
        visited[1] = true;
        bool flag = false;
        ll m = n;
        while(!dq.empty()){
            ll node = dq.front();
            if(depth[node]*2 - 1 >= m) break;
            dq.pop_front();
            for(ll child: tree[node]){
                if(!visited[child]){
                    visited[child] = true;
                    dq.push_back(child);
                    depth[child] = depth[node] + 1;
                    if(tree[child].size() == 2) m = min(depth[child]*2, m);
                    else if(tree[child].size() == 1) m = min(depth[child]*2 - 1, m);
                }
            }
        }
        cout << n - m << '\n';
    }
    return 0;
}