#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    ll sum_a = accumulate(a.begin(), a.end(), (ll)0), sum_b = accumulate(b.begin(), b.end(), (ll)0);
    ll l = 0, r = (sum_b + k)/sum_a, result = 0;
    while(l <= r){
        ll m = (l + r)/2, need_k = 0;
        for(int i = 0; i < n; i++) need_k += max(m*a[i] - b[i], (ll)0);
        if(need_k <= k){
            result = m;
            l = m + 1;
        } else r = m - 1;
    }
    cout << result << '\n';
    return 0;
}