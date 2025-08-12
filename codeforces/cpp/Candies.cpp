#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll l = 1, r = n, k = n;
    while(l <= r){
        ll v = 0, p = 0, m = (l + r)/2, candies = n;
        while(candies){
            v += min(m, candies);
            candies -= min(m, candies);
            p += candies/10;
            candies -= candies/10;
        }
        if(v >= p){
            k = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << k << '\n';
    return 0;
}