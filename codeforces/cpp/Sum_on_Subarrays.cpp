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
        ll n, k;
        cin >> n >> k;
        vector<ll> res(n, -1000);
        ll c = 1;
        while(k - c >= 0){
            res[c - 1] = 2;
            k -= c;
            c++;
        }
        c--;
        if(k != 0) res[c] = 2*(k - c) - 1;
        for(ll x: res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}