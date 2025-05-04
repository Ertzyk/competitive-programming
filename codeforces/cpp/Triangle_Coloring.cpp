#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 998244353;

ll fast_exponentiation(ll a, ll b, ll m){
    if(b == 0) return 1;
    ll result = 1;
    while(b > 0){
        if(b%2 == 1){
            result *= a;
            result %= m;
        }
        a = a*a%m;
        b /= 2;
    }
    return result;
}

ll inverse(ll a, ll m){
    return fast_exponentiation(a, m - 2, m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll result = 1;
    for(int i = 1; i <= n/6; i++){
        result *= (n/6 + i);
        result %= MOD;
        result *= inverse(i, MOD);
        result %= MOD;
    }
    for(int i = 0; i < n/3; i++){
        int a, b, c, z = 0;
        cin >> a >> b >> c;
        int m = min(min(a, b), c);
        if(m == a) z++;
        if(m == b) z++;
        if(m == c) z++;
        result *= z;
        result %= MOD;
    }
    cout << result;
    return 0;
}