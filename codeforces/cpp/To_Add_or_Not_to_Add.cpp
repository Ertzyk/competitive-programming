#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), prefix_sum(n + 1);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    for(ll i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    ll l = 1, r = n, result = 1, num = a[0];
    while(l <= r){
        ll m = (l + r)/2;
        bool found = false;
        for(ll i = m; i <= n; i++){
            if(a[i - 1]*m - prefix_sum[i] + prefix_sum[i - m] <= k){
                found = true;
                l = m + 1;
                result = m;
                num = a[i - 1];
                break;
            }
        }
        if(!found) r = m - 1;
    }
    cout << result << ' ' << num << '\n';
    return 0;
}