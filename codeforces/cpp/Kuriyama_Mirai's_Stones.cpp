#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, cur = 0;
    cin >> n;
    vector<ll> v(n), precal_v(n + 1), precal_v_sorted(n + 1);
    for(ll &x: v) cin >> x;
    cin >> m;
    precal_v[0] = precal_v_sorted[0] = 0;
    for(int i = 0; i < n; i++){
        cur += v[i];
        precal_v[i + 1] = cur;
    }
    cur = 0;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        cur += v[i];
        precal_v_sorted[i + 1] = cur;
    }
    while(m--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) cout << precal_v[r] - precal_v[l - 1] << '\n';
        else cout << precal_v_sorted[r] - precal_v_sorted[l - 1] << '\n';
    }
    return 0;
}