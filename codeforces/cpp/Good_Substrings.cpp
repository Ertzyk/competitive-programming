#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

vector<ll> prefix_function(string s){
    ll n = s.size();
    vector<ll> pi(n, 0);
    for(ll i = 1; i < n; i++){
        ll j = pi[i - 1];
        while(j > 0 && s[j] != s[i]) j = pi[j - 1];
        if(s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, ch;
    ll k;
    cin >> s >> ch >> k;
    ll n = s.size(), res = 0;
    vector<ll> bad_letter_pref(n + 1);
    for(ll i = 1; i <= n; i++){
        bad_letter_pref[i] = bad_letter_pref[i - 1] + 1 - (ch[s[i - 1] - 'a'] - '0');
    }
    for(ll start = n - 1; start >= 0; start--){
        vector<ll> pi = prefix_function(s.substr(start, n));
        ll M = *max_element(pi.begin(), pi.end());
        for(ll i = start + M; i < n; i++){
            if(bad_letter_pref[i + 1] - bad_letter_pref[start] <= k) res++;
            else break;
        }
    }
    cout << res << '\n';
    return 0;
}