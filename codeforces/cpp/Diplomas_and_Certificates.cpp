#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    cout << n/2/(k + 1) << ' ' << n/2/(k + 1)*k << ' ' << n - n/2/(k + 1) - n/2/(k + 1)*k << '\n';
    return 0;
}