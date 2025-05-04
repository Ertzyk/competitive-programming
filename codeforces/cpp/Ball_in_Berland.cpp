#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        ll k;
        cin >> a >> b >> k;
        vector<ll> A(a), B(b);
        for(int i = 0; i < k; i++){
            ll x;
            cin >> x;
            A[x - 1]++;
        }
        for(int i = 0; i < k; i++){
            ll x;
            cin >> x;
            B[x - 1]++;
        }
        ll s = 0;
        for(ll x: A) s += x*x;
        for(ll x: B) s += x*x;
        cout << (k*(k + 1) - s)/2 << '\n';
    }
    return 0;
}