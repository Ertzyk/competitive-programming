#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll y, x;
        cin >> y >> x;
        if(x >= y) cout << ((x%2) ? x*x - y + 1 : (x - 1)*(x - 1) + y) << '\n';
        else cout << ((y%2) ? (y - 1)*(y - 1) + x : y*y - x + 1) << '\n';
    }
    return 0;
}