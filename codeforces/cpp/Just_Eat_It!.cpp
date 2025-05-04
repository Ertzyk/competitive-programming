#include <iostream>
#include <vector>
#include <climits>
#include <numeric>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for(ll &x: a) cin >> x;
        ll cur_sum = 0, adel = INT_MIN, yasser = accumulate(a.begin(), a.end(), (ll)0);
        for(int i = 0; i < n - 1; i++){
            cur_sum += a[i];
            adel = max(adel, cur_sum);
            if(cur_sum < 0) cur_sum = 0;
        }
        cur_sum = 0;
        for(int i = 1; i < n; i++){
            cur_sum += a[i];
            adel = max(adel, cur_sum);
            if(cur_sum < 0) cur_sum = 0;
        }
        cout << ((yasser > adel) ? "YES\n" : "NO\n");
    }
    return 0;
}