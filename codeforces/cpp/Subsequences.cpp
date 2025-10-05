#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct FenwickTree{
    vector<ll> bit;
    ll n;
    FenwickTree(int n) : n(n), bit(n, 0) {}
    ll sum(int r){
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    k++;
    if(k > n){
        cout << "0\n";
        return 0;
    }
    vector<FenwickTree> dp(k + 1, FenwickTree(n));
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        dp[1].add(a - 1, 1);
        for(int j = 2; j <= k; j++) dp[j].add(a - 1, dp[j - 1].sum(a - 2));
    }
    cout << dp[k].sum(n - 1) << '\n';
    return 0;
}