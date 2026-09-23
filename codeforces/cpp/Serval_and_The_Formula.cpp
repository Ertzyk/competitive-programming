#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll x, y, m = 1;
        cin >> x >> y;
        if(x == y){
            cout << "-1\n";
            continue;
        }
        while(m < max(x, y)){
            m <<= 1;
        }
        cout << m - max(x, y) << '\n';
    }
    return 0;
}