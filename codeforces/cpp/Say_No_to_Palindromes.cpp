#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vector<ll> abc(n, 1), acb(n, 1), bac(n, 1), bca(n, 1), cab(n, 1), cba(n, 1);
    for(ll i = 0; i < n; i++){
        if(i%3 == 0){
            if(s[i] == 'a'){
                abc[i] = 0;
                acb[i] = 0;
            } else if(s[i] == 'b'){
                bac[i] = 0;
                bca[i] = 0;
            } else {
                cab[i] = 0;
                cba[i] = 0;
            }
        } else if(i%3 == 1){
            if(s[i] == 'a'){
                bac[i] = 0;
                cab[i] = 0;
            } else if(s[i] == 'b'){
                abc[i] = 0;
                cba[i] = 0;
            } else {
                acb[i] = 0;
                bca[i] = 0;
            }
        } else {
            if(s[i] == 'a'){
                bca[i] = 0;
                cba[i] = 0;
            } else if(s[i] == 'b'){
                acb[i] = 0;
                cab[i] = 0;
            } else {
                abc[i] = 0;
                bac[i] = 0;
            }
        }
    }
    vector<ll> pr_abc(n + 1, 0), pr_acb(n + 1, 0), pr_bac(n + 1, 0), pr_bca(n + 1, 0), pr_cab(n + 1, 0), pr_cba(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        pr_abc[i] = pr_abc[i - 1] + abc[i - 1];
        pr_acb[i] = pr_acb[i - 1] + acb[i - 1];
        pr_bac[i] = pr_bac[i - 1] + bac[i - 1];
        pr_bca[i] = pr_bca[i - 1] + bca[i - 1];
        pr_cab[i] = pr_cab[i - 1] + cab[i - 1];
        pr_cba[i] = pr_cba[i - 1] + cba[i - 1];
    }
    while(m--){
        ll l, r;
        cin >> l >> r;
        ll x = min(pr_abc[r] - pr_abc[l - 1], pr_acb[r] - pr_acb[l - 1]);
        ll y = min(pr_bac[r] - pr_bac[l - 1], pr_bca[r] - pr_bca[l - 1]);
        ll z = min(pr_cab[r] - pr_cab[l - 1], pr_cba[r] - pr_cba[l - 1]);
        cout << min(x, min(y, z)) << '\n';
    }
    return 0;
}