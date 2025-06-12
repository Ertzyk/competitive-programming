#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, s;
    cin >> n >> m >> s;
    cout << ((n - 1)%s + 1)*((m - 1)%s + 1)*((n - 1)/s + 1)*((m - 1)/s + 1) << '\n';
    return 0;
}