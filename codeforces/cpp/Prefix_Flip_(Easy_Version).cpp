#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        string a, b;
        cin >> n >> a >> b;
        vector<ll> d(n);
        ll k = 0;
        for(ll i = n - 1; i >= 0; i -= 2){
            d[i] = k;
            k++;
        }
        k = n - 1;
        for(ll i = n - 2; i >= 0; i -= 2){
            d[i] = k;
            k--;
        }
        vector<ll> res;
        res.reserve(2*n);
        ll reverse = 1;
        for(ll i = n - 1; i >= 1; i--){
            if(b[i] != (a[d[i]]^reverse)) res.push_back(1);
            res.push_back(i + 1);
            reverse = 1 - reverse;
        }
        if(b[0] == (a[d[0]]^reverse)) res.push_back(1);
        cout << res.size() << ' ';
        for(ll x: res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}