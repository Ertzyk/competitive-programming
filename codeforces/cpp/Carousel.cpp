#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        ll changes = 0;
        for(ll i = 0; i < n - 1; i++) if(a[i] != a[i + 1]) changes++;
        if(a[0] != a[n - 1]) changes++;
        vector<ll> res(n);
        if(changes == 0){
            cout << "1\n";
            for(ll i = 0; i < n; i++) cout << 1 << " \n"[i == n - 1];
        } else if(changes == n && (n&1) == 1){
            cout << "3\n3 ";
            for(ll i = 1; i < n; i++) cout << 2 - (i&1) << " \n"[i == n - 1];
        } else if((n&1) == 1){
            cout << "2\n";
            bool not_switched = false;
            ll cur = 1;
            for(ll i = 0; i < n; i++){
                cout << cur << " \n"[i == n - 1];
                cur = 3 - cur;
                if(!not_switched && i < n - 1 && a[i] == a[i + 1]){
                    not_switched = true;
                    cur = 3 - cur;
                }
            }
        } else {
            cout << "2\n";
            for(ll i = 0; i < n; i++) cout << 2 - (i&1) << " \n"[i == n - 1];
        }
    }
    return 0;
}