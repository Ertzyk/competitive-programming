#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> p(n);
    for(ll &x: p) cin >> x;
    sort(p.begin(), p.end());
    ll l = 0, r = n - 1, res = 0;
    while(l < r){
        if(p[l] + p[r] <= x) l++;
        res++;
        r--;
    }
    if(l == r) res++;
    cout << res << '\n';
    return 0;
}