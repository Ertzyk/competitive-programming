#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, res = 0, cur = 0;
    cin >> n;
    set<ll> st;
    while(n--){
        ll a;
        cin >> a;
        cur += a;
        if(cur == 0 || st.count(cur)){
            st.clear();
            res++;
            cur = a;
        }
        st.insert(cur);
    }
    cout << res << '\n';
    return 0;
}