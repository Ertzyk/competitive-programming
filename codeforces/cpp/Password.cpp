#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> prefix_function(const string &s){
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
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> pi = prefix_function(s);
    if(pi[n - 1] == 0) {
        cout << "Just a legend\n";
        return 0;
    }
    for(ll i = 1; i <= n - 2; i++){
        if(pi[i] == pi[n - 1]){
            cout << s.substr(0, pi[n - 1]) << '\n';
            return 0;
        }
    }
    if(pi[pi[n - 1] - 1] != 0){
        cout << s.substr(0, pi[pi[n - 1] - 1]) << '\n';
    } else {
        cout << "Just a legend\n";
    }
    return 0;
}