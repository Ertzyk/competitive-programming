#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
using ll = long long;

void divide_and_conquer(ll l, ll r, const vector<ll> &a, const vector<ll> &prefix_sum, unordered_set<ll> &poss_s){
    poss_s.insert(prefix_sum[r + 1] - prefix_sum[l]);
    ll mid = (a[l] + a[r])/2;
    ll k = upper_bound(a.begin() + l, a.begin() + r + 1, mid) - a.begin();
    if(k != l && k != r + 1){
        divide_and_conquer(l, k - 1, a, prefix_sum, poss_s);
        divide_and_conquer(k, r, a, prefix_sum, poss_s);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        vector<ll> a(n), pre_sum_a(n + 1, 0);
        for(ll &x: a) cin >> x;
        sort(a.begin(), a.end());
        unordered_set<ll> poss_s;
        for(int i = 1; i <= n; i++) pre_sum_a[i] = pre_sum_a[i - 1] + a[i - 1];
        divide_and_conquer(0, n - 1, a, pre_sum_a, poss_s);
        while(q--){
            ll s;
            cin >> s;
            cout << ((poss_s.count(s)) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}