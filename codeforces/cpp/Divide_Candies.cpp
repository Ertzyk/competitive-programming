#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, result = 0;
    cin >> n >> m;
    vector<ll> mod_m(m);
    for(ll i = 1; i <= m; i++) mod_m[i*i%m] += n/m;
    for(ll i = 1; i <= n%m; i++) mod_m[i*i%m]++;
    result += mod_m[0]*mod_m[0];
    for(ll i = 1; i < m; i++) result += mod_m[i]*mod_m[m - i];
    cout << result;
    return 0;
}