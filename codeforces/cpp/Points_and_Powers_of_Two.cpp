#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, mn = 1000000000, mx = -1000000000, result = 1;
    cin >> n;
    set<ll> st;
    vector<ll> res(2, 0);
    res.reserve(2);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        st.insert(x);
        mx = max(mx, x);
        mn = min(mn, x);
    }
    for(ll x: st){
        for(ll r = 1; x - r >= mn || x + r <= mx; r <<= 1){
            bool b1 = (st.find(x - r) != st.end()), b2 = (st.find(x + r) != st.end());
            if(b1 && b2){
                cout << "3\n" << x - r << ' ' << x << ' ' << x + r << '\n';
                return 0;
            }
            if(result == 1){
                if(b1){
                    result = 2;
                    res[0] = x - r;
                    res[1] = x;
                } else if(b2){
                    result = 2;
                    res[0] = x;
                    res[1] = x + r;
                }
            }
        }
    }
    cout << result << '\n';
    if(result == 1) cout << mn << '\n';
    else cout << res[0] << ' ' << res[1] << '\n';
    return 0;
}