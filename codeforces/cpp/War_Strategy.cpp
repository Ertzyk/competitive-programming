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
        ll n, m, k;
        cin >> n >> m >> k;
        ll l = 2, r = n, res = 1;
        while(l <= r){
            ll mid = (l + r)/2, b = 0;
            if((mid - 1)/2 > min(k - 1, n - k)){
                b = 2*mid - min(k - 1, n - k) - 3;
            } else {
                b = 3*mid/2 - 2;
            }
            if(b <= m){
                l = mid + 1;
                res = mid;
            } else r = mid - 1;
        }
        cout << res << '\n';
    }
    return 0;
}