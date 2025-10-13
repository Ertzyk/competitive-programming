#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t, l, r, ans = 0, m = 1;
    cin >> t >> l >> r;
    vector<ll> ld(r + 1, 0), pr, f(r + 1, 0);
    for(ll i = 2; i <= r; i++){
        if(ld[i] == 0){
            ld[i] = i;
            pr.push_back(i);
        }
        for(ll j = 0; pr[j]*i <= r; j++){
            ld[pr[j]*i] = pr[j];
            if(pr[j] == ld[i]) break;
        }
    }
    for(ll i = 2; i <= r; i++){
        f[i] = (i*(ld[i] - 1)/2 + f[i/ld[i]])%MOD;
        if(i >= l){
            ans += f[i]*m;
            m = m*t%MOD;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}