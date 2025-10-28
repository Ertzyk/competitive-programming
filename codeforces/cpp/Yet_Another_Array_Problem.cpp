#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, p = 2;
        cin >> n;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        bool flag = false;
        while(true){
            for(ll x: a) if(gcd(x, p) == 1){
                cout << p << '\n';
                flag = true;
                break;
            }
            if(flag) break;
            p++;
        }
    }
    return 0;
}