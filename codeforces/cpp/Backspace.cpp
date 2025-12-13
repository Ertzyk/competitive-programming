#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        ll sp = 1, tp = 0;
        while(sp < s.size() && tp < t.size()){
            if(s[sp] == t[tp]) tp++;
            else sp++;
            sp++;
        }
        if(tp == t.size() && (s.size() - sp)%2 == 0){
            cout << "YES\n";
            continue;
        }
        tp = sp = 0;
        if(s.size()%2 != t.size()%2) sp = 2;
        while(sp < s.size() && tp < t.size()){
            if(s[sp] == t[tp]) tp++;
            else sp++;
            sp++;
        }
        cout << ((tp == t.size() && (s.size() - sp)%2 == 0) ? "YES\n" : "NO\n");
    }
    return 0;
}