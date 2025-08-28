#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> c(n);
    for(ll &x: c) cin >> x;
    ll prev_cost_normal = 0, prev_cost_rev = c[0], cur_cost_normal = LLONG_MAX, cur_cost_rev = LLONG_MAX;
    string prev;
    cin >> prev;
    for(int i = 1; i < n; i++){
        string cur;
        cin >> cur;
        string rev_prev(prev.rbegin(), prev.rend()), rev_cur(cur.rbegin(), cur.rend());
        if(cur >= prev && prev_cost_normal != LLONG_MAX) cur_cost_normal = prev_cost_normal;
        if(cur >= rev_prev && prev_cost_rev != LLONG_MAX) cur_cost_normal = min(cur_cost_normal, prev_cost_rev);
        if(rev_cur >= prev && prev_cost_normal != LLONG_MAX) cur_cost_rev = prev_cost_normal + c[i];
        if(rev_cur >= rev_prev && prev_cost_rev != LLONG_MAX) cur_cost_rev = min(cur_cost_rev, prev_cost_rev + c[i]);
        prev_cost_normal = cur_cost_normal;
        prev_cost_rev = cur_cost_rev;
        cur_cost_normal = cur_cost_rev = LLONG_MAX;
        prev = cur;
    }
    if(prev_cost_normal == LLONG_MAX && prev_cost_rev == LLONG_MAX) cout << "-1\n";
    else cout << min(prev_cost_normal, prev_cost_rev) << '\n';
    return 0;
}