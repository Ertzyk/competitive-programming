#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

string num_to_string(ll n){
    string res;
    while(n > 0){
        res += (char)(n%26 + 'a');
        n /= 26;
    }
    while(res.size() < 7) res += 'a';
    return res;
}

ll string_to_num(string s){
    ll res = 0, m = 1;
    for(char ch: s){
        res += m*(ch - 'a');
        m *= 26;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t;
    cin >> t;
    if(t == "first"){
        ll n;
        cin >> n;
        string res;
        while(n--){
            ll a;
            cin >> a;
            res += num_to_string(a);
        }
        cout << res << '\n';
    } else {
        string s;
        cin >> s;
        cout << s.size()/7 << '\n';
        for(int i = 0; i < s.size(); i += 7){
            cout << (int)string_to_num(s.substr(i, 7)) << " \n"[i == s.size() - 7];
        }
        cout << '\n';
    }
    return 0;
}