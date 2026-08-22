#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
using ll = long long;

struct SparseTable {
    ll n;
    vector<vector<ll>> st;
    ll K; 
    vector<ll> lg;

    SparseTable(const vector<ll>& a){
        n = (ll)a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for(ll i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        K = lg[n];
        st.resize(K + 1);
        st[0] = a; 
        for(ll i = 1; i <= K; i++){
            st[i].resize(n - (1 << i) + 1);
            for(ll j = 0; j + (1 << i) <= n; j++){
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    ll minimum(ll L, ll R){
        ll i = lg[R - L + 1];
        return min(st[i][L], st[i][R - (1 << i) + 1]);
    }

    ll f(ll a, ll b){
        return min(a, b);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, cnt = 0, cur = 0;
    cin >> n;
    vector<pair<ll, ll>> tvs(n);
    for(pair<ll, ll> &pr: tvs) cin >> pr.first >> pr.second;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        mp[tvs[i].first] = -1;
        mp[tvs[i].second] = -1;
        mp[tvs[i].second + 1] = -1;
    }
    for(auto pr: mp){
        mp[pr.first] = cnt;
        cnt++;
    }
    for(ll i = 0; i < n; i++){
        tvs[i].first = mp[tvs[i].first];
        tvs[i].second = mp[tvs[i].second];
    }
    vector<ll> a(cnt + 1, 0), b(cnt + 1, 0);
    for(ll i = 0; i < n; i++){
        a[tvs[i].first]++;
        a[tvs[i].second + 1]--;
    }
    for(ll i = 0; i < cnt + 1; i++){
        cur += a[i];
        b[i] = cur;
    }
    for(ll i = 0; i < cnt + 1; i++){
        if(b[i] >= 2) b[i] = 1;
        else b[i] = 0;
    }
    SparseTable st(b);
    bool flag = false;
    for(ll i = 0; i < n; i++){
        if(st.minimum(tvs[i].first, tvs[i].second) == 1){
            cout << i + 1 << '\n';
            flag = true;
            break;
        }
    }
    if(!flag) cout << "-1\n";
    return 0;
}