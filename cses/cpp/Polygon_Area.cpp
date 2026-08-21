#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a = 0, prevx, prevy, curx, cury, stx, sty;
    cin >> n >> prevx >> prevy;
    stx = prevx;
    sty = prevy;
    for(ll i = 0; i < n - 1; i++){
        cin >> curx >> cury;
        a += (cury + prevy)*(curx - prevx);
        prevx = curx;
        prevy = cury;
    }
    a += (cury + sty)*(stx - curx);
    cout << abs(a) << '\n';
    return 0;
}