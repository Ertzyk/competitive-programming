#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    cout << n/a*p + n/b*q - n/lcm(a, b)*min(p, q);
    return 0;
}