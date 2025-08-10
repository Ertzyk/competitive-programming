#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == s[i]) cout << "0 ";
        else cout << "1 ";
    }
    if(s.back() == 'a') cout << "1\n";
    else cout << "0\n";
    return 0;
}