#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    vector<ll> a(m);
    vector<pair<ll, ll>> b(m), ab, cd(k + 1);
    for(ll &x: a) cin >> x;
    for(int i = 0; i < m; i++){
        ll p;
        cin >> p;
        b[i] = {p, i};
    }
    sort(b.begin(), b.end(), [](pair<ll, ll> y, pair<ll, ll> z){if(y.first != z.first) return y.first > z.first; return y.second > z.second;});
    for(int i = 0; i < m; i++){
        while(!ab.empty() && ab.back().second >= a[b[i].second]) ab.pop_back();
        ab.push_back({b[i].first, a[b[i].second]});
    }
    ab.push_back({0, x});
    cd[0] = {0, 0};
    for(int i = 1; i <= k; i++){
        ll p;
        cin >> p;
        cd[i] = {0, p};
    }
    for(int i = 1; i <= k; i++){
        ll p;
        cin >> p;
        cd[i].first = p;
    }
    ll result = n*x;
    int pa = 0, pc = 0;
    while(pa < ab.size() && pc < k + 1){
        if(ab[pa].first + cd[pc].first <= s){
            result = min(result, (n - cd[pc].second)*ab[pa].second);
            pc++;
        } else pa++;
    }
    cout << result << '\n';
    return 0;
}