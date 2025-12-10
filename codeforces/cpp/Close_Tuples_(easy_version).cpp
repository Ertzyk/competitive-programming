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
    vector<vector<ll>> newton(200000, vector<ll>(3, 0));
    for(ll i = 0; i < 200000; i++) newton[i][0] = 1;
    for(ll i = 1; i < 3; i++) newton[i][i] = 1;
    for(ll n = 2; n < 200000; n++){
        for(ll k = 1; k <= min(n - 1, (ll)2); k++){
            newton[n][k] = newton[n - 1][k - 1] + newton[n - 1][k];
        }
    }
    while(t--){
        ll n, l = 0, res = 0;
        cin >> n;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        sort(a.begin(), a.end());
        for(ll r = 2; r < n; r++){
            while(a[r] - a[l] > 2) l++;
            res += newton[r - l][2];
        }
        cout << res << '\n';
    }
    return 0;
}