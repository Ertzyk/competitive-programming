#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;

struct FenwickTree{
    vector<ll> bit;
    ll n;
    FenwickTree(ll n) : n(n), bit(n, 0) {}
    ll sum(ll r){
        ll res = 0;
        while(r >= 0){
            res += bit[r];
            r = (r&(r + 1)) - 1;
        }
        return res;
    }
    void add(ll i, ll delta){
        while(i < n){
            bit[i] += delta;
            i |= (i + 1);
        }
    }
};

int main(){
    //UNFINISHED
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, result = 0;
    cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;
    FenwickTree ft(n);
    vector<pair<ll, ll>> negative;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            result++;
            ft.add(i, a[i]);
        } else negative.push_back({a[i], i});
    }
    sort(negative.rbegin(), negative.rend());
    return 0;
}