#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, c, d;
        cin >> n >> c >> d;
        set<ll> a;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            a.insert(x);
        }
        ll ans = (n - a.size())*c, cur_min = LLONG_MAX, i = 0;
        if(!a.count(1)){
            ans += d;
            a.insert(1);
        }
        for(auto it = a.begin(); it != a.end(); ++it){
            cur_min = min(cur_min, ((ll)a.size() - i - 1)*c + (*it - i - 1)*d);
            i++;
        }
        cout << ans + cur_min << '\n';
    }
    return 0;
}