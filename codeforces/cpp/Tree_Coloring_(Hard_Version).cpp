#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>
using namespace std;
using ll = long long;
int main(){
    //UNFINISHED
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
        vector<ll> parent(n + 1, 0);
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
                    parent[neighbor] = node;
                }
            }
        }
        ll M = 0;
        for(auto ar: depths){
            M = max(M, (ll)ar.size());
        }
        if(M == 1){
            cout << 2 << '\n';
            vector<vector<ll>> result(2);
            for(ll i = 0; i < n; i++){
                result[i%2].push_back(depths[i][0]);
            }
            for(auto ar: result){
                cout << ar.size() << ' ';
                for(ll x: ar) cout << x << ' ';
                cout << '\n';
            }
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
        ll k = M + ((add_one) ? 1 : 0);
        cout << k << '\n';
        vector<ll> color(n + 1, -1);
        color[0] = color[1] = 0;
        set<ll> st;
        for(ll i = 0; i < k; i++){
            st.insert(i);
        }
        for(ll layer = 1; layer < n; layer++){
            if(depths[layer].size() == k){
                set<ll> stcp = st;
                set<ll> used;
                for(ll x: depths[layer - 1]){
                    if(tree[x].size() > 1 || x == 1) used.insert(color[x]);
                }
                while(!used.empty()){
                    for(ll x: used) cout << x << ' ';
                    cout << "\n";
                    for(ll i = 0; i < depths[layer].size(); i++){
                        if(color[depths[layer][i]] != -1) continue;
                        auto it = used.begin();
                        cout << *it << ' ' << depths[layer][i] << '\n';
                        if(color[parent[depths[layer][i]]] != *it){
                            color[depths[layer][i]] = *it;
                            st.erase(*it);
                            used.erase(*it);
                        }
                        // } else if(used.size() > 1){
                        //     it = next(it);
                        //     color[depths[layer][i]] = *it;
                        //     st.erase(*it);
                        //     used.erase(*it);
                        // }
                    }
                }
                for(ll node: depths[layer]){
                    if(color[node] != -1) continue;
                    ll p = *stcp.begin();
                    color[node] = p;
                    stcp.erase(p);
                }
            } else {
                set<ll> stcp = st;
                for(ll node: depths[layer]){
                    auto it = stcp.begin();
                    if(*it != color[parent[node]]){
                        color[node] = *it;
                        stcp.erase(it);
                    } else {
                        it = next(it);
                        color[node] = *it;
                        stcp.erase(it);
                    }
                }
            }
        }
        vector<vector<ll>> result(k);
        for(ll i = 1; i <= n; i++){
            cout << color[i] << '\n';
        }
        // for(ll i = 1; i <= n; i++){
        //     result[color[i]].push_back(i);
        // }
        // for(auto ar: result){
        //     cout << ar.size() << ' ';
        //     for(ll x: ar) cout << x << ' ';
        //     cout << '\n';
        // }
    }
    return 0;
}