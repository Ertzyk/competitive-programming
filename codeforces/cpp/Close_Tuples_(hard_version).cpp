#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    vector<vector<ll>> newton(200000, vector<ll>(100, 0));
    for(ll i = 0; i < 200000; i++) newton[i][0] = 1;
    for(ll i = 1; i < 100; i++) newton[i][i] = 1;
    for(ll n = 2; n < 200000; n++){
        for(ll k = 1; k <= min(n - 1, (ll)99); k++){
            newton[n][k] = newton[n - 1][k - 1] + newton[n - 1][k];
            newton[n][k] %= MOD;
        }
    }
    while(t--){
        ll n, m, k, l = 0, res = 0;
        cin >> n >> m >> k;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        sort(a.begin(), a.end());
        for(ll r = m - 1; r < n; r++){
            while(a[r] - a[l] > k) l++;
            res += newton[r - l][m - 1];
            res %= MOD;
        }
        cout << res << '\n';
    }
    return 0;
}