#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n), max_left(n), max_right(n), min_left(n), min_right(n);
    for(ll &x: a) cin >> x;
    ll cur_max = a[0], cur_min = a[0], ans = LLONG_MIN;
    max_left[0] = min_left[0] = a[0];
    for(int i = 1; i < n; i++){
        if(cur_max < a[i]) cur_max = a[i];
        if(cur_min > a[i]) cur_min = a[i];
        max_left[i] = cur_max;
        min_left[i] = cur_min;
    }
    cur_max = cur_min = max_right[n - 1] = min_right[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(cur_max < a[i]) cur_max = a[i];
        if(cur_min > a[i]) cur_min = a[i];
        max_right[i] = cur_max;
        min_right[i] = cur_min;
    }
    for(int i = 0; i < n; i++) ans = max(ans, q*a[i] + ((p >= 0) ? max_left[i] : min_left[i])*p + ((r >= 0) ? max_right[i] : min_right[i])*r);
    cout << ans << '\n';
    return 0;
}