#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, x, res = 0;
        cin >> n >> x;
        for(ll a = 1; a <= n; a++){
            for(ll b = 1; a*b <= n; b++){
                res += max((ll)0, min(x - a - b, (n - a*b)/(a + b)));
            }
        }
        cout << res << '\n';
    }
    return 0;
}