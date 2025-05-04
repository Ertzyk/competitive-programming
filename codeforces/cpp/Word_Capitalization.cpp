#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if(s[0] >= 'a') s[0] = (char)(s[0] - 'a' + 'A');
    cout << s;
    return 0;
}