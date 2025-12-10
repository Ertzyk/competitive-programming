#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<vector<ll>> prefix_sum((n - 1)/m + 2, vector<ll>(m, 0));
    for(int i = 0; i < n; i++) prefix_sum[i/m + 1][i%m] = prefix_sum[i/m][i%m] + a[i];
    ll cur = 0;
    for(int i = 0; i < n; i++){
        cur += prefix_sum[i/m + 1][i%m];
        cout << cur << " \n"[i == n - 1];
    }
    return 0;
}