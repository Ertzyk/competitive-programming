#include <iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;
    string cur_min = "-1";
    for(int i = 0; i < s.size() - 1; i++){
        if((s[i] - '0')%2 == 0){
            if((s[i] - '0') < (s[s.size() - 1] - '0')){
                swap(s[i], s[s.size() - 1]);
                cout << s;
                return;
            } else {
                swap(s[i], s[s.size() - 1]);
                cur_min = s;
                swap(s[i], s[s.size() - 1]);
            }
        }
    }
    cout << cur_min;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}