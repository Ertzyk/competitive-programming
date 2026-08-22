#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), prefix_xor(n + 1, 0);
    for(ll &x: a) cin >> x;
    for(ll i = 1; i <= n; i++) prefix_xor[i] = (prefix_xor[i - 1]^a[i - 1]);
    while(q--){
        ll x, y;
        cin >> x >> y;
        cout << (prefix_xor[y]^prefix_xor[x - 1]) << '\n';
    }
    return 0;
}