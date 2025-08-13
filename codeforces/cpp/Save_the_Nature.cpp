#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        ll n, x, a, y, b, k;
        cin >> n;
        vector<ll> p(n);
        for(ll &x: p) cin >> x;
        sort(p.rbegin(), p.rend());
        vector<ll> p_sumed(n + 1, 0);
        for(int i = 1; i <= n; i++) p_sumed[i] = p[i - 1] + p_sumed[i - 1];
        cin >> x >> a >> y >> b >> k;
        ll ans = n + 1, l = 1, r = n, c = lcm(a, b);
        while(l <= r){
            ll m = (l + r)/2;
            ll a0 = m/a - m/c, b0 = m/b - m/c, c0 = m/c;
            ll res = p_sumed[c0]/100*(x + y);
            if(x > y) res += (p_sumed[c0 + a0] - p_sumed[c0])/100*x + (p_sumed[c0 + a0 + b0] - p_sumed[c0 + a0])/100*y;
            else res += (p_sumed[c0 + b0] - p_sumed[c0])/100*y + (p_sumed[c0 + a0 + b0] - p_sumed[c0 + b0])/100*x;
            if(res >= k){
                r = m - 1;
                ans = m;
            } else l = m + 1;
        }
        cout << ((ans == n + 1) ? -1 : ans) << '\n';
    }
    return 0;
}