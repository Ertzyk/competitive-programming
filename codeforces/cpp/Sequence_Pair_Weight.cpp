#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1){
            ll a;
            cin >> a;
            cout << "0\n";
        } else if (n == 2){
            ll a1, a2;
            cin >> a1 >> a2;
            if(a1 == a2) cout << "1\n";
            else cout << "0\n";
        } else {
            unordered_map<ll, ll> cnt;
            for(ll i = 0; i < n; i++){
                ll a;
                cin >> a;
                cnt[a]++;
            }
            ll result = 0;
            for(auto pr: cnt) result += (pr.second - 1)*pr.second;
            result <<= n - 3;
            cout << result << '\n';
        }
    }
    return 0;
}