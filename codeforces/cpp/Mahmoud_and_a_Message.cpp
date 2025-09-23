#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, longest_sub = 1, l = 0, r = 0, minimum_sub = 1, max_len = LLONG_MAX, start = 0;
    string s;
    cin >> n >> s;
    vector<ll> a(26);
    for(ll &x: a) cin >> x;
    vector<ll> dp(n + 1);
    dp[0] = dp[1] = 1;
    for(ll i = 2; i <= n; i++){
        ll min_ai = LLONG_MAX;
        for(ll j = i; j > 0; j--){
            min_ai = min(min_ai, a[s[j - 1] - 'a']);
            if(i - j + 1 > min_ai) break;
            dp[i] += dp[j - 1];
        }
        dp[i] %= 1000000007;
    }
    deque<ll> dq;
    dq.push_back(a[s[0] - 'a']);
    while(r < n){
        if(r - l + 1 <= dq.front()){
            longest_sub = max(longest_sub, r - l + 1);
            r++;
            while(!dq.empty() && dq.back() > a[s[r] - 'a']) dq.pop_back();
            dq.push_back(a[s[r] - 'a']);
        } else {
            if(dq.front() == a[s[l] - 'a']) dq.pop_front();
            l++;
        }
    }
    for(int i = 0; i < n; i++){
        max_len = min(max_len, a[s[i] - 'a']);
        if(i - start + 1 > max_len){
            minimum_sub++;
            max_len = a[s[i] - 'a'];
            start = i;
        }
    }
    cout << dp[n] << '\n' << longest_sub << '\n' << minimum_sub << '\n';
    return 0;
}