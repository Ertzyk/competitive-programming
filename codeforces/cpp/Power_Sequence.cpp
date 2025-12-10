#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, c = 1, res = LLONG_MAX;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    sort(a.begin(), a.end());
    bool end = false;
    while(true){
        ll c2 = 1, diff = 0;
        for(int i = 0; i < n; i++){
            diff += abs(a[i] - c2);
            c2 *= c;
            if(diff > 1000000000000000 || c2 > 1000000000000000){
                end = true;
                break;
            }
        }
        if(end) break;
        res = min(res, diff);
        c++;
    }
    cout << res << '\n';
    return 0;
}