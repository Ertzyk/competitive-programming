#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll h, n, lastT = 1;
        cin >> h >> n;
        vector<ll> a(n), c(n);
        for(ll &x: a) cin >> x;
        for(ll &x: c) cin >> x;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> min_heap;
        for(ll i = 0; i < n; i++) min_heap.push({1, i});
        while(h > 0){
            auto [cooldown, idx] = min_heap.top();
            min_heap.pop();
            h -= a[idx];
            min_heap.push({cooldown + c[idx], idx});
            lastT = cooldown;
        }
        cout << lastT << '\n';
    }
    return 0;
}