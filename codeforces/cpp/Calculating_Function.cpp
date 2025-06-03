#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n%2) cout << -n/2 - 1 << '\n';
    else cout << n/2 << '\n';
    return 0;
}