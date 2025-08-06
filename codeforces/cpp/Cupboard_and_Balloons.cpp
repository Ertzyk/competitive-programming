#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll r, h;
    cin >> r >> h;
    ll a = h%r;
    cout << h/r*2 + ((2*a < r) ? 1 : ((4*a*a < 3*r*r) ? 2 : 3)) << '\n';
    return 0;
}