#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        if(a + b > n || ((a == 0) != (b == 0))){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<ll> res_a, res_b;
        res_a.reserve(n);
        res_b.reserve(n);
        while(a + b < n){
            res_a.push_back(n);
            res_b.push_back(n);
            n--;
        }
        if(a >= b){
            ll pa = b + 1, pb = 1;
            while(pa <= n){
                res_a.push_back(pa);
                res_b.push_back(pb);
                pa++;
                pb++;
            }
            pa = 1;
            while(pb <= n){
                res_a.push_back(pa);
                res_b.push_back(pb);
                pa++;
                pb++;
            }
        } else {
            ll pa = 1, pb = a + 1;
            while(pb <= n){
                res_a.push_back(pa);
                res_b.push_back(pb);
                pa++;
                pb++;
            }
            pb = 1;
            while(pa <= n){
                res_a.push_back(pa);
                res_b.push_back(pb);
                pa++;
                pb++;
            }
        }
        for(ll x: res_a) cout << x << ' ';
        cout << '\n';
        for(ll x: res_b) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}