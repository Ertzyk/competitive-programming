#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        ll n = s.size();
        bool flag = false;
        for(ll d = n/2; d > 0; d--){
            ll conseq = 0;
            for(ll i = 0; i + d < n; i++){
                if(s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') conseq++;
                else conseq = 0;
                if(conseq == d){
                    cout << 2*d << '\n';
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout << "0\n";
    }
    return 0;
}