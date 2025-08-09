#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if(s[0] == 'S' && s[n - 1] == 'F') cout << "YES\n";
    else cout << "NO\n";
    return 0;
}