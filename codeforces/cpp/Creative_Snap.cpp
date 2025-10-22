#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
 
ll solve(ll l, ll r, const vector<ll>& a, const ll A, const ll B){
    ll av = lower_bound(a.begin(), a.end(), r + 1) - lower_bound(a.begin(), a.end(), l);
    if(av == 0) return A;
    if(l == r) return B*av;
    return min(solve(l, (l + r)/2, a, A, B) + solve((l + r)/2 + 1, r, a, A, B), B*av*(r - l + 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, A, B, u = 1;
    cin >> n >> k >> A >> B;
    vector<ll> a(k);
    for(ll &x: a) cin >> x;
    vector<ll> powerof2;
    while(u < 2000000000){
        powerof2.push_back(u);
        u *= 2;
    }
    sort(a.begin(), a.end());
    cout << solve(1, powerof2[n], a, A, B) << '\n';
    return 0;
}