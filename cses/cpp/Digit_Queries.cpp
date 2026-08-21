#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        ll d = 1, pow_10_d = 1;
        while(k > 9*pow_10_d*d){
            k -= 9*pow_10_d*d;
            d++;
            pow_10_d *= 10;
        }
        if(d == 1){
            cout << k << '\n';
            continue;
        }
        ll m = k%d, a = (k - 1)/d;
        if(m == 0) m = d;
        for(ll i = 0; i < d - m; i++) a /= 10;
        cout << ((m == 1) ? a%10 + 1 : a%10) << '\n';
    }
    return 0;
}