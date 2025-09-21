#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve(ll upper, vector<ll>& result, ll& res){
    if(upper < 1) return;
    ll m = 1, k = 0;
    while(m <= upper) m *= 2;
    m /= 2;
    for(ll i = 2*m - upper - 1; i <= upper; i++){
        result[i] = upper - k;
        k++;
        res += 2*m - 1;
    }
    solve(2*m - upper - 2, result, res);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        vector<ll> result(r + 1, 0);
        ll res = 0;
        solve(r, result, res);
        cout << res << '\n';
        for(ll x: result) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}