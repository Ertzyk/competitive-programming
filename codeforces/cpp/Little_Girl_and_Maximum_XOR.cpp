#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l, r, d = 0;
    cin >> l >> r;
    while(l != r){
        l >>= 1;
        r >>= 1;
        d++;
    }
    cout << ((ll)1 << d) - 1 << '\n';
    return 0;
}