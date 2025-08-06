#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    ll l = 1, r = 1;
    while(s[l - 1] == s[l]) l++;
    while(s[n - r] == s[n - r - 1]) r++;
    if(s[0] == s[n - 1]) cout << (l + 1)*(r + 1)%998244353 << '\n';
    else cout << l + r + 1 << '\n';
    return 0;
}