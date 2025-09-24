#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> d(n), a(m);
    for(ll &x: d) cin >> x;
    for(ll &x: a) cin >> x;
    unordered_set<ll> sett;
    ll l = -1, r = n - 1, result = -2;
    for(ll i = 0; i < n; i++){
        if(d[i]) sett.insert(d[i]);
        if(sett.size() == m){
            l = i;
            break;
        }
    }
    if(l == -1){
        cout << "-1\n";
        return 0;
    }
    while(l <= r){
        ll mid = (l + r)/2, cur_sum = 0;
        vector<ll> last(m);
        for(ll i = 0; i <= mid; i++) if(d[i]) last[d[i] - 1] = i;
        sort(last.begin(), last.end());
        bool found = false;
        for(ll i = 0; i < m; i++){
            cur_sum += a[d[last[i]] - 1];
            if(last[i] - i < cur_sum){
                l = mid + 1;
                found = true;
                break;
            }
        }
        if(!found){
            r = mid - 1;
            result = mid;
        }
    }
    cout << result + 1 << '\n';
    return 0;
}