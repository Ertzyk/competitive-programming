#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, d, h, m, res = 0;
    cin >> x >> d >> h >> m;
    res += (23 - h)*60 + 60 - m;
    if(x != 5 && d - x == 22) res += 1440;
    if(x == 5){
        res += 1440*(29 - d);
        if(d < 29 || h < 2) res -= 60;
    }
    cout << res << '\n';
    return 0;
}