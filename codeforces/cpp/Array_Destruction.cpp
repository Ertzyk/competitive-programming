#include <iostream>
#include <map>
#include <utility>
#include <vector>
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
        map<ll, ll> a;
        for(ll i = 0; i < 2*n; i++){
            ll p;
            cin >> p;
            a[p]++;
        }
        ll M = a.rbegin()->first;
        if(a[M] > 1) a[M]--;
        else a.erase(M);
        bool flag2 = false;
        for(auto pr: a){
            ll x = M;
            map<ll, ll> a_cp(a.begin(), a.end());
            if(pr.second > 1) a_cp[pr.first]--;
            else a_cp.erase(pr.first);
            bool flag = false;
            vector<pair<ll, ll>> res(n - 1);
            for(ll i = 0; i < n - 1; i++){
                ll q = a_cp.rbegin()->first;
                if(a_cp[q] > 1) a_cp[q]--;
                else a_cp.erase(q);
                if(a_cp.count(x - q)){
                    res[i].first = q;
                    res[i].second = x - q;
                    if(a_cp[x - q] > 1) a_cp[x - q]--;
                    else a_cp.erase(x - q);
                    x = q;
                } else {
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << "YES\n" << M + pr.first << '\n' << M << ' ' << pr.first << '\n';
                for(ll i = 0; i < n - 1; i++) cout << res[i].first << ' ' << res[i].second << '\n';
                flag2 = true;
                break;
            }
        }
        if(!flag2) cout << "NO\n";
    }
    return 0;
}