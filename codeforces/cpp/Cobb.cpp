#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        ll M = LLONG_MIN;
        for(ll sum = max(3, (int)(2*floor(sqrt(max(n*n - n*(1 + 2*k), (ll)1))) + 1)); sum <= 2*n - 1; sum++){
            for(ll i = max((ll)1, sum - n); i < (sum + 1)/2; i++){
                M = max(M, i*(sum - i) - k*(a[i - 1]|a[sum - i - 1]));
            }
        }
        cout << M << '\n';
    }
    return 0;
}