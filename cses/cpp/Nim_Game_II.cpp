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
        ll n, my_xor = 0;
        cin >> n;
        for(ll i = 0; i < n; i++){
            ll x;
            cin >> x;
            my_xor ^= x;
        }
        if(my_xor%4 == 0) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}