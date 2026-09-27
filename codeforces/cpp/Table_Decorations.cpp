#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll r, g, b;
    cin >> r >> g >> b;
    cout << min((r + g + b)/3, min(min(r, g), b) + max(max(min(r, g), min(r, b)), min(g, b))) << '\n';
    return 0;
}