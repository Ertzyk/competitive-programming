#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll h, w, n;
    cin >> h >> w >> n;
    vector<ll> d(n);
    for(ll &x: d) cin >> x;
    if(h%d[0] || w%d[0]){
        cout << -1;
        return 0;
    }
    ll cur_h = h/d[0], cur_w = w/d[0], result = (h/d[0])*(w/d[0]);
    for(int i = 1; i < n; i++){
        ll k = d[i]/d[i - 1];
        result -= (cur_h/k)*(cur_w/k)*(k*k - 1);
        cur_h /= k;
        cur_w /= k;
    }
    cout << result;
    return 0;
}