#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b, k, s = 0;
    cin >> n >> a >> b >> k;
    vector<ll> h(n), special_moves(n);
    for(ll &x: h) cin >> x;
    for(ll i = 0; i < n; i++){
        h[i] %= a + b;
        if(h[i] == 0) h[i] = a + b;
        special_moves[i] = (h[i] - 1)/a;
    }
    sort(special_moves.begin(), special_moves.end());
    for(int i = 0; i < n; i++){
        s += special_moves[i];
        if(s > k){
            cout << i << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    return 0;
}