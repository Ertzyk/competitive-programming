#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k, m = 1;
        cin >> n >> k;
        while(2*k - 1 > n){
            k -= (n + 1)/2;
            n -= (n + 1)/2;
            m *= 2;
        }
        cout << (2*k - 1)*m << '\n';
    }
    return 0;
}