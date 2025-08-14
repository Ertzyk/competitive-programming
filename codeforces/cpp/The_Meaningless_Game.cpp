#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll cube_root(ll n){
    ll l = 0, r = n, ans = 0;
    while(l <= r){
        ll m = (l + r)/2;
        if(m != 0 && m > n/m/m) r = m - 1;
        else {
            l = m + 1;
            ans = m;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        ll d = cube_root(a*b);
        if(d*d*d != a*b){
            cout << "No\n";
            continue;
        }
        ll g = gcd(a, b);
        ll l = a*b/g;
        g *= g;
        if(g%l == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}