#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n), t(n/2), s((n - 1)/2);
        for(ll &x: a) cin >> x;
        ll result = 0;
        for(int i = 0; i < n; i += 2) result += a[i];
        for(int i = 1; i < n; i += 2) t[i/2] = a[i] - a[i - 1];
        ll max_val1 = 0, cur_val = 0, max_val2 = 0;
        for(int r = 0; r < n/2; r++){
            cur_val += t[r];
            if(cur_val < 0) cur_val = 0;
            max_val1 = max(max_val1, cur_val);
        }
        for(int i = 2; i < n; i += 2) s[i/2 - 1] = a[i - 1] - a[i];
        cur_val = 0;
        for(int r = 0; r < (n - 1)/2; r++){
            cur_val += s[r];
            if(cur_val < 0) cur_val = 0;
            max_val2 = max(max_val2, cur_val);
        }
        cout << result + max(max_val1, max_val2) << '\n';
    }
    return 0;
}