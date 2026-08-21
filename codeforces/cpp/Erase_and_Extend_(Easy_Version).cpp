#include <iostream>
using namespace std;
using ll = long long;

ll compare(ll a, ll b, const ll &k, const string &s){
    for(ll i = min(a, b) + 1; i < k; i++){
        if(s[i%a] < s[i%b]) return a;
        if(s[i%a] > s[i%b]) return b;
    }
    return b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    string s, result;
    cin >> n >> k >> s;
    for(ll i = 1; i < n; i++){
        if(s[0] < s[i]){
            s = s.substr(0, i);
            break;
        }
    }
    ll mini = s.size();
    for(ll i = 1; i < s.size(); i++){
        if(s[i] == s[0]){
            mini = compare(i, mini, k, s);
        }
    }
    s = s.substr(0, mini);
    while(result.size() < k) result += s;
    while(result.size() > k) result.pop_back();
    cout << result << '\n';
    return 0;
}