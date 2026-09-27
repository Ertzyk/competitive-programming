#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> prefix_function(string s){
    ll n = s.size();
    vector<ll> pi(n, 0);
    for(ll i = 1; i < n; i++){
        ll j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll l = 0, r = s.size() - 1;
        while(l < r && s[l] == s[r]){
            l++;
            r--;
        }
        if(r <= l){
            cout << s << '\n';
            continue;
        }
        string t = s.substr(l, r - l + 1);
        string t_rev = string(t.rbegin(), t.rend());
        vector<ll> pr_palindrome = prefix_function(t + '#' + t_rev), sf_palindrome = prefix_function(t_rev + '#' + t);
        if(pr_palindrome[pr_palindrome.size() - 1] >= sf_palindrome[sf_palindrome.size() - 1]){
            cout << s.substr(0, l + pr_palindrome[pr_palindrome.size() - 1]) + s.substr(r + 1, l) << '\n';
        } else {
            cout << s.substr(0, l) + t_rev.substr(0, sf_palindrome[sf_palindrome.size() - 1]) + s.substr(r + 1, l) << '\n';
        }
    }
    return 0;
}