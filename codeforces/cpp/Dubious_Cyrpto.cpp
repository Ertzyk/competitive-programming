#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r, m;
        cin >> l >> r >> m;
        for(ll a = l; a <= r; a++){
            ll k = m%a;
            if(k <= r - l && m - k > 0){
                cout << a << ' ' << r << ' ' << r - k << '\n';
                break;
            }
            if(k + r - l >= a && m + a - k > 0){
                cout << a << ' ' << l << ' ' << a - k + l << '\n';
                break;
            }
        }
    }
    return 0;
}