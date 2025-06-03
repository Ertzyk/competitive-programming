#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) s[i] = '1';
        else s[i] = '0';
    }
    cout << s << '\n';
    return 0;
}