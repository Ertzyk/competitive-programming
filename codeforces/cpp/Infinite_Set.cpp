#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;

void to_add(ll x, vector<ll> &cnt_seg){
    int c = 0;
    while(x > 0){
        c++;
        x /= 2;
    }
    cnt_seg[c]++;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, p, res = 0;
    cin >> n >> p;
    set<ll> st;
    vector<ll> cnt_seg(36, 0);
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        st.insert(a);
    }
    for(ll x: st){
        bool add = true;
        ll r = x;
        while(x != 1 && x%4 != 2){
            if(x%2) x /= 2;
            else x /= 4;
            if(st.count(x)){
                add = false;
                break;
            }
        }
        if(add) to_add(r, cnt_seg);
    }
    for(ll i = 2; i < 36; i++){
        cnt_seg[i] += cnt_seg[i - 1] + cnt_seg[i - 2];
        cnt_seg[i] %= MOD;
    }
    for(ll i = 1; i <= min(p, (ll)35); i++){
        res += cnt_seg[i];
        res %= MOD;
    }
    ll a = cnt_seg[34], b = cnt_seg[35];
    for(ll i = 0; i < p - 35; i++){
        res += a + b;
        res %= MOD;
        a += b;
        swap(a, b);
        a %= MOD;
        b %= MOD;
    }
    cout << res << '\n';
    return 0;
}