#include <iostream>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;

ll fast_exp(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll fact = 1, p = fast_exp(2, n - 1, MOD);
    for(ll i = 2; i <= n; i++){
        fact *= i;
        fact %= MOD;
    }
    cout << (fact - p + 2*MOD)%MOD << '\n';
    return 0;
}