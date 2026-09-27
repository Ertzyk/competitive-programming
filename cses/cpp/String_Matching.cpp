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
    string s, t;
    cin >> t >> s;
    vector<ll> pi = prefix_function(s + '#' + t);
    ll res = 0;
    for(ll i = 2*s.size(); i < pi.size(); i++){
        if(pi[i] == s.size()){
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}