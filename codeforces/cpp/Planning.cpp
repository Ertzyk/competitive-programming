#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    set<int> possibilities;
    ll result = 0;
    vector<int> result_v(n);
    for(int i = 1; i <= n; i++){
        int r;
        cin >> r;
        a[i - 1] = {r, i};
    }
    sort(a.rbegin(), a.rend());
    for(int i = k + 1; i <= k + n; i++) possibilities.insert(i);
    for(int i = 0; i < n; i++){
        auto [c, idx] = a[i];
        int p = *possibilities.lower_bound(idx);
        possibilities.erase(p);
        result_v[idx - 1] = p;
        result += (ll)(p - idx)*(ll)c;
    }
    cout << result << '\n';
    for(int x: result_v) cout << x << ' ';
    cout << '\n';
    return 0;
}