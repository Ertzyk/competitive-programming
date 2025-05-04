#include <iostream>
using namespace std;
using ll = long long;
const long long MOD = 1e9 + 9;

ll fast_exponentiation(ll a, ll b, ll m){
    ll result = 1;
    while(b > 0){
        if(b%2) result = result*a%m;
        a = a*a%m;
        b /= 2;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    cout << ((n/k <= n - m) ? m : ((2*(fast_exponentiation(2, n/k - n + m, MOD) - 1)*k%MOD + m - n/k*k + (n - m)*k%MOD + MOD)%MOD));
    return 0;
}