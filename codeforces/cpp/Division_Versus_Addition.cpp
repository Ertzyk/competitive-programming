#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll score(ll n){
    ll result = 0;
    n--;
    while(n > 0){
        n /= 2;
        result++;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), b(n), prefixb(n + 1), prefix_power2(n + 1);
        for(ll &x: a) cin >> x;
        for(int i = 0; i < n; i++) b[i] = score(a[i]);
        for(int i = 0; i < n; i++) prefixb[i + 1] = prefixb[i] + b[i];
        for(int i = 0; i < n; i++) prefix_power2[i + 1] = prefix_power2[i] + (((((a[i] - 1)&(a[i] - 2)) == 0) && a[i] != 2)? 1 : 0);
        while(q--){
            ll l, r;
            cin >> l >> r;
            cout << prefixb[r] - prefixb[l - 1] - (prefix_power2[r] - prefix_power2[l - 1] + 1)/2 << '\n';
        }
    }
    return 0;
}