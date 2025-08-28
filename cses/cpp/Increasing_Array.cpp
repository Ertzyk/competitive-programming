#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll M = 0, ans = 0;
    while(n--){
        ll x;
        cin >> x;
        M = max(M, x);
        ans += M - x;
    }
    cout << ans << '\n';
    return 0;
}