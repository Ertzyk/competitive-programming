#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k, ap = 0, bp = 0, res = 0;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(ll &x: a) cin >> x;
    for(ll &x: b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(ap < n && bp < m){
        if(b[bp] < a[ap] - k) bp++;
        else if(b[bp] > a[ap] + k) ap++;
        else {
            res++;
            ap++;
            bp++;
        }
    }
    cout << res << '\n';
    return 0;
}