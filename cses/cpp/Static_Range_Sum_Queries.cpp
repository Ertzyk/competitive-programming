#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), prefix_sum(n + 1, 0);
    for(ll &x: a) cin >> x;
    for(ll i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    while(q--){
        ll x, y;
        cin >> x >> y;
        cout << prefix_sum[y] - prefix_sum[x - 1] << '\n';
    }
    return 0;
}