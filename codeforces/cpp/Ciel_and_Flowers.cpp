#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll r, g, b;
    cin >> r >> g >> b;
    if(r == 0 || g == 0 || b == 0) cout << r/3 + g/3 + b/3;
    else if(r%3 != g%3 && g%3 != b%3 && b%3 != r%3) cout << (r + g + b)/3 - 1;
    else cout << (r + g + b)/3;
    return 0;
}