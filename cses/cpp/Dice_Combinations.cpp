#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a = 1, b = 0, c = 0, d = 0, e = 0, f = 0;
    cin >> n;
    while(n--){
        ll temp = a;
        a += b + c + d + e + f;
        a %= 1000000007;
        f = e;
        e = d;
        d = c;
        c = b;
        b = temp;
    }
    cout << a << '\n';
    return 0;
}