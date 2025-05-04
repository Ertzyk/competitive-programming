#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k;
        ll n, a = 1, b = 1;
        cin >> n >> k;
        while(k--){
            int r, c;
            cin >> r >> c;
            n -= ((r == c) ? 1 : 2);
        }
        for(ll i = 2; i <= n; i++){
            b = 2*(i - 1)*b + a;
            b %= MOD;
            swap(a, b);
        }
        cout << a << '\n';
    }
    return 0;
}