#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll n = stoll(s.substr(0, s.size() - 1)), x;
    if(s[s.size() - 1] == 'f') x = 1;
    else if(s[s.size() - 1] == 'e') x = 2;
    else if(s[s.size() - 1] == 'd') x = 3;
    else if(s[s.size() - 1] == 'a') x = 4;
    else if(s[s.size() - 1] == 'b') x = 5;
    else x = 6;
    cout << (n - 1)/4*16 + (n + 1)%2*7 + x << '\n';
    return 0;
}