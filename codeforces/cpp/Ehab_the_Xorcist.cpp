#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll u, v;
    cin >> u >> v;
    if(u > v || (v - u)%2) cout << -1;
    else if(u == 0 && v == 0) cout << 0;
    else if(u == 0) cout << "2\n" << v/2 << ' ' << v/2;
    else if(u == v) cout << "1\n" << u;
    else if((u&((v - u)/2)) == 0) cout << "2\n" << (u|((v - u)/2)) << ' ' << (v - u)/2;
    else cout << "3\n" << u << ' ' << (v - u)/2 << ' ' << (v - u)/2;
    return 0;
}