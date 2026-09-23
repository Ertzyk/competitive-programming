#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 100000000;

ll calculate(ll a, ll b, ll k, ll type, vector<vector<vector<ll>>>& dp1, vector<vector<vector<ll>>>& dp2, const ll& k1, const ll& k2){
    if(type == 1){
        if(dp1[a][b][k] != -1) return dp1[a][b][k];
        if(a == k && b == 0){
            dp1[a][b][k] = 1;
            return 1;
        }
        if(a < k){
            dp1[a][b][k] = 0;
            return 0;
        }
        if(k == 1){
            ll res = 0;
            for(ll i = 1; i <= k2; i++){
                res += calculate(a - 1, b, i, 2, dp1, dp2, k1, k2);
            }
            dp1[a][b][k] = res%MOD;
            return res;
        }
        dp1[a][b][k] = calculate(a - k + 1, b, 1, 1, dp1, dp2, k1, k2)%MOD;
        return dp1[a][b][k];
    } else {
        if(dp2[a][b][k] != -1) return dp2[a][b][k];
        if(b == k && a == 0){
            dp2[a][b][k] = 1;
            return 1;
        }
        if(b < k){
            dp2[a][b][k] = 0;
            return 0;
        }
        if(k == 1){
            ll res = 0;
            for(ll i = 1; i <= k1; i++){
                res += calculate(a, b - 1, i, 1, dp1, dp2, k1, k2);
            }
            dp2[a][b][k] = res%MOD;
            return res;
        }
        dp2[a][b][k] = calculate(a, b - k + 1, 1, 2, dp1, dp2, k1, k2)%MOD;
        return dp2[a][b][k];
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n1, n2, k1, k2, res = 0;
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<ll>>> dp1(n1 + 1, vector<vector<ll>>(n2 + 1, vector<ll>(k1 + 1, -1)));
    vector<vector<vector<ll>>> dp2(n1 + 1, vector<vector<ll>>(n2 + 1, vector<ll>(k2 + 1, -1)));
    for(ll i = 1; i <= k1; i++) res += calculate(n1, n2, i, 1, dp1, dp2, k1, k2);
    for(ll i = 1; i <= k2; i++) res += calculate(n1, n2, i, 2, dp1, dp2, k1, k2);
    cout << res%MOD << '\n';
    return 0;
}