#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    cout << (((n/k)%2) ? "YES\n" : "NO\n");
    return 0;
}