#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> factorial(n + 1);
    factorial[0] = 1;
    for(ll i = 1; i <= n; i++) factorial[i] = factorial[i - 1]*i%m;
    ll result = 0;
    for(ll k = 1; k <= n; k++){
        result += (factorial[k]*factorial[n - k + 1]%m)*(n - k + 1)%m;
        result %= m;
    }
    cout << result;
    return 0;
}