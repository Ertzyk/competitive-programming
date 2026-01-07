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
        cin >> n;
        vector<ll> a(n);
        for(ll &x : a) cin >> x;
        if(a[0] == 1 || a[n - 1] == 1){
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}