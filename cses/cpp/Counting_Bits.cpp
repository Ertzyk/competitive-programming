#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll n){
    if(n == 0) return 0;
    ll d = 0, cp_n = n;
    while(cp_n > 0){
        d++;
        cp_n >>= 1;
    }
    if((n&(n + 1)) == 0) return ((ll)1 << (d - (ll)1))*d;
    return ((ll)1 << (d - (ll)2))*(d - 3) + n + (ll)1 + solve(n - ((ll)1 << (d - (ll)1)));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << solve(n) << '\n';
    return 0;
}