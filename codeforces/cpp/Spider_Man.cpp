#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll s = 0;
    while(n--){
        ll a;
        cin >> a;
        s += a - 1;
        cout << ((s%2) ? 1 : 2) << '\n';
    }
    return 0;
}