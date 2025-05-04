#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        ll result = 0;
        cin >> n >> m;
        vector<ll> a(m);
        for(int i = 0; i < m; i++){
            ll x;
            cin >> x;
            if(x == n) a[i] = x - 1;
            else a[i] = x;
        }
        sort(a.begin(), a.end());
        vector<ll> postfix_sum(m + 1);
        postfix_sum[m] = 0;
        for(int i = m - 1; i >= 0; i--) postfix_sum[i] = postfix_sum[i + 1] + a[i];
        for(int i = 0; i < m; i++){
            auto lb = lower_bound(a.begin(), a.end(), n - a[i] - 1);
            result += (ll)(a[i] - n + 1)*(ll)(a.size() - max((int)distance(a.begin(), lb), i + 1)) + postfix_sum[max((int)distance(a.begin(), lb), i + 1)];
        }
        cout << 2*result << '\n';
    }
    return 0;
}