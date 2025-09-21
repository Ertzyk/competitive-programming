#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
 
void solve(ll l_idx, ll r_idx, ll min_num, ll max_num, vector<ll>& result, ll& res, ll sub){
    if(l_idx > r_idx) return;
    if(max_num < 1){
        result[l_idx] = sub;
        return;
    }
    ll m = 1;
    while(m <= max_num) m *= 2;
    m /= 2;
    if(min_num >= m){
        res += (max_num - min_num + 1)*m;
        solve(l_idx, r_idx, min_num - m, max_num - m, result, res, sub + m);
    } else if(m - min_num <= max_num - m + 1){
        ll k = 1;
        for(ll i = min_num; i < 2*(m - min_num) + min_num; i++){
            result[l_idx - 1 + k] = 2*(m - min_num) + min_num - k + sub;
            k++;
            res += 2*m - 1;
        }
        solve(l_idx + k - 1, r_idx, 2*(m - min_num) + min_num, max_num, result, res, sub);
    } else {
        ll k = 0;
        for(ll i = 2*m - max_num - 1; i <= max_num; i++){
            result[i - max_num + r_idx] = max_num - k + sub;
            k++;
            res += 2*m - 1;
        }
        solve(l_idx, 2*m - 2*max_num - 2 + r_idx, min_num, 2*m - max_num - 2, result, res, sub);
    }
    return;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        vector<ll> result(r - l + 1, 0);
        ll res = 0;
        solve(0, r - l, l, r, result, res, 0);
        cout << res << '\n';
        for(ll x: result) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}