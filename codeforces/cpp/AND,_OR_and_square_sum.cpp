#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    vector<ll> cnt_bits(20, 0);
    for(ll i = 0; i < n; i++){
        ll k = 0;
        while(a[i] > 0){
            if((a[i]&1) == 1) cnt_bits[k]++;
            a[i] >>= 1;
            k++;
        }
    }
    ll res = 0;
    while(true){
        ll c = 0;
        for(ll i = 0; i < 20; i++){
            if(cnt_bits[i] > 0){
                c += (1 << i);
                cnt_bits[i]--;
            }
        }
        if(c == 0) break;
        res += c*c;
    }
    cout << res << '\n';
    return 0;
}