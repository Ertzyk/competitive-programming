#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, k, res = 0;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        for(ll i = 0; i < n; i++){
            res += a[i]/k;
            a[i] %= k;
        }
        sort(a.rbegin(), a.rend());
        ll l = 1, r = n/2, w = 0;
        while(l <= r){
            ll m = (l + r)/2;
            bool flag = false;
            for(ll i = 0; i < m; i++){
                if(a[i] + a[2*m - 1 - i] < k){
                    flag = true;
                    break;
                }
            }
            if(flag) r = m - 1;
            else {
                l = m + 1;
                w = m;
            }
        }
        cout << res + w << '\n';
    }
    return 0;
}