#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        ll s = accumulate(a.begin(), a.end(), (ll)0);
        if(k*s < x){
            cout << 0 << '\n';
            continue;
        }
        ll m = x%s, cur_s = 0, stop = -1;
        for(ll i = n - 1; i >= 0; i--){
            if(cur_s < m) cur_s += a[i];
            else {
                stop = i;
                break;
            }
        }
        cout << n*(k - 1) - x/s*n + stop + 2 << '\n';
    }
    return 0;
}