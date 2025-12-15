#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

void dfs(ll node, vector<ll> &res, vector<ll> &a, vector<vector<ll>> &tree){
    ll m = LLONG_MAX;
    for(ll child: tree[node]){
        dfs(child, res, a, tree);
        m = min(m, res[child]);
    }
    res[node] = ((m == LLONG_MAX) ? a[node] : min((a[node] + m)/2, m));
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m = LLONG_MAX;
        cin >> n;
        vector<ll> a(n), res(n, 0);
        vector<vector<ll>> tree(n + 1);
        for(ll &x: a) cin >> x;
        for(ll i = 1; i < n; i++){
            ll p;
            cin >> p;
            tree[p - 1].push_back(i);
        }
        for(ll child: tree[0]){
            dfs(child, res, a, tree);
            m = min(m, res[child]);
        }
        cout << a[0] + m << '\n';
    }
    return 0;
}