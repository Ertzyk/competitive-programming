#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll fast_exponentiation(ll a, ll b, ll m){
    if(b == 0) return 1;
    if(b%2) return a*fast_exponentiation(a, b - 1, m)%m;
    return fast_exponentiation(a*a%m, b/2, m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll l, r, k, base;
        cin >> l >> r >> k;
        if(k >= 10) {
            cout << "0\n";
            continue;
        }
        else if(k >= 5) base = 2;
        else if(k == 4) base = 3;
        else if(k == 3) base = 4;
        else if(k == 2) base = 5;
        else base = 10;
        cout << (fast_exponentiation(base, r, MOD) - fast_exponentiation(base, l, MOD) + MOD)%MOD << '\n';
    }
    return 0;
}