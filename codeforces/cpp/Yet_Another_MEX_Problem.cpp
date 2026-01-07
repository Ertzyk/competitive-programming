#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k, p = 0;
        cin >> n >> k;
        vector<ll> a(n), mex(n + 1, false);
        for(ll &x: a) cin >> x;
        for(ll x: a) mex[x] = true;
        while(mex[p]) p++;
        cout << min(p, k - 1) << '\n';
    }
    return 0;
}