#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    cout << ((s[a - 1] == s[b - 1]) ? 0 : 1) << '\n';
    return 0;
}