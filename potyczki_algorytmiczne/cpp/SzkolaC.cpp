#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, s;
    cin >> n >> m >> s;
    vector<pair<ll, ll>> left_intervals, right_intervals;
    for(int i = 0; i < m; i++){
        ll l, r;
        cin >> l >> r;
        if(r < s) left_intervals.push_back({r, l});
        else if(l > s) right_intervals.push_back({l, r});
        else{
            left_intervals.push_back({s, l});
            right_intervals.push_back({s, r});
        }
    }
    sort(left_intervals.rbegin(), left_intervals.rend());
    sort(right_intervals.begin(), right_intervals.end());
    ll l = s, r = s;
    for(auto p: left_intervals){
        if(l != p.first) break;
        l = p.second - 1;
    }
    for(auto p: right_intervals){
        if(r != p.first) break;
        r = p.second + 1;
    }
    ll result = LLONG_MAX;
    if(l > 0 && abs(result - s) > s - l) result = l;
    if(r <= n && abs(result - s) > r - s) result = r;
    cout << result;
    return 0;
}