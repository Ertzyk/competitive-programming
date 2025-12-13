#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, res = 0;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        vector<ll> result(n);
        for(ll i = 0; i < n; i++){
            ll x;
            cin >> x;
            a[i] = {x, i};
        }
        sort(a.begin(), a.end());
        for(auto pr: a) res += pr.first - a[0].first + 1;
        result[a[0].second] = res;
        for(ll i = 1; i < n; i++){
            res += (a[i].first - a[i - 1].first)*(2*i - n);
            result[a[i].second] = res;
        }
        for(ll i = 0; i < n; i++) cout << result[i] << " \n"[i == n - 1];
    }
    return 0;
}