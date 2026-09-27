#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<string> s(n);
        bool one = false, flag = false;
        for(ll i = 0; i < n; i++){
            string str;
            cin >> str;
            if(str.size() == 1) one = true;
            s[i] = str;
        }
        if(one){
            cout << "YES\n";
            continue;
        }
        for(ll i = 0; i < n; i++){
            if(s[i].size() == 2){
                if(s[i][0] == s[i][1]){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            } else {
                if(s[i][0] == s[i][2]){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            }
        }
        if(flag) continue;
        bitset<729> bst2, bs2, bs3;
        bitset<19683> bst3;
        for(ll i = 0; i < n; i++){
            if(s[i].size() == 2){
                bst2[(s[i][0] - 'a' + 1) + 27*(s[i][1] - 'a' + 1)] = 1;
            } else {
                bst3[(s[i][0] - 'a' + 1) + 27*(s[i][1] - 'a' + 1) + 729*(s[i][2] - 'a' + 1)] = 1;
            }
        }
        for(ll i = 0; i < n; i++){
            if(s[i].size() == 2){
                if(bst2[27*(s[i][0] - 'a' + 1) + (s[i][1] - 'a' + 1)]){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            } else {
                if(bst3[729*(s[i][0] - 'a' + 1) + 27*(s[i][1] - 'a' + 1) + (s[i][2] - 'a' + 1)]){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            }
        }
        if(flag) continue;
        for(ll i = 0; i < n; i++){
            if(s[i].size() == 2){
                if(bs3[27*(s[i][0] - 'a' + 1) + (s[i][1] - 'a' + 1)]){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
                bs2[(s[i][0] - 'a' + 1) + 27*(s[i][1] - 'a' + 1)] = 1;
            } else {
                if(bs2[27*(s[i][1] - 'a' + 1) + (s[i][2] - 'a' + 1)]){
                    cout << "YES\n";
                    flag = true;
                    break;
                }
                bs3[(s[i][0] - 'a' + 1) + 27*(s[i][1] - 'a' + 1)] = 1;
            }
        }
        if(!flag) cout << "NO\n";
    }
    return 0;
}