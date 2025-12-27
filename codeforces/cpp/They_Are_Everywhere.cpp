#include <iostream>
#include <map>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    string s;
    cin >> n >> s;
    map<char, ll> cnt;
    for(char ch: s) cnt[ch]++;
    ll g = cnt.size(), l = 1, r = n - 1, res = n;
    while(l <= r){
        cnt.clear();
        ll m = (l + r)/2;
        for(ll i = 0; i < m; i++) cnt[s[i]]++;
        ll M = (ll)cnt.size();
        for(ll i = m; i < n; i++){
            cnt[s[i]]++;
            if(cnt[s[i - m]] == 1) cnt.erase(s[i - m]);
            else cnt[s[i - m]]--;
            M = max(M, (ll)cnt.size());
        }
        if(M == g){
            res = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << res << '\n';
    return 0;
}