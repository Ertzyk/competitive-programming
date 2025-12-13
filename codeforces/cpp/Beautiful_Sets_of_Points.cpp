#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    cout << min(n, m) + 1 << '\n';
    for(ll i = 0; i <= min(n, m); i++) cout << i << ' ' << min(n, m) - i << '\n';
    return 0;
}