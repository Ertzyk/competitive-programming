#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll hamming_weight(ll n){
    ll cnt = 0;
    while(n > 0){
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, res = 1000, m = 1;
        cin >> n;
        vector<ll> factorials;
        for(ll i = 2; m <= n; i++){
            factorials.push_back(m);
            m *= i;
        }
        for(ll i = 0; i < (1 << factorials.size()); i++){
            ll j = 0, cur = n, cnt = 0, temp = i;
            while(i > 0){
                if(i%2){
                    cur -= factorials[j];
                    cnt++;
                }
                j++;
                i /= 2;
            }
            if(cur >= 0) res = min(res, cnt + hamming_weight(cur));
            i = temp;
        }
        cout << res << '\n';
    }
    return 0;
}