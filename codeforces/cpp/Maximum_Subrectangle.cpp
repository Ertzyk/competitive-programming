#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, x;
    cin >> n >> m;
    vector<ll> nv(n), mv(m), conSumN(n + 1), conSumM(m + 1), minSumByLenN(n + 1, LLONG_MAX), minSumByLenM(m + 1, LLONG_MAX);
    for(ll &p: nv) cin >> p;
    for(ll &p: mv) cin >> p;
    cin >> x;
    for(int i = 1; i <= n; i++) conSumN[i] = conSumN[i - 1] + nv[i - 1];
    for(int i = 1; i <= m; i++) conSumM[i] = conSumM[i - 1] + mv[i - 1];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            minSumByLenN[i] = min(minSumByLenN[i], conSumN[i + j] - conSumN[j]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= m - i; j++){
            minSumByLenM[i] = min(minSumByLenM[i], conSumM[i + j] - conSumM[j]);
        }
    }
    ll npoint = 1, mpoint = m, ans = 0;
    while(npoint <= n && mpoint > 0){
        if(minSumByLenN[npoint]*minSumByLenM[mpoint] <= x){
            ans = max(ans, npoint*mpoint);
            npoint++;
        } else mpoint--;
    }
    cout << ans << '\n';
    return 0;
}