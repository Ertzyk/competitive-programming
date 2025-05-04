#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h1(n), h2(n);
    for(ll &x: h1) cin >> x;
    for(ll &x: h2) cin >> x;
    ll up = h1[0], down = h2[0];
    for(int i = 1; i < n; i++){
        ll temp = up;
        up = max(h1[i] + down, up);
        down = max(h2[i] + temp, down);
    }
    cout << max(up, down);
    return 0;
}