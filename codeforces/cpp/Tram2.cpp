#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, x1, x2, t1, t2, p, d, ans = 0;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    if(d == 1){
        if(p <= x1) ans += (x1 - p)*t1;
        else {
            ans += (2*s - p - x1)*t1;
            d = -1;
        }
    } else {
        if(p >= x1) ans += (p - x1)*t1;
        else {
            ans += (p + x1)*t1;
            d = 1;
        }
    }
    if(d == 1) ans += ((x1 <= x2) ? x2 - x1 : 2*s - x1 - x2)*t1;
    else ans += ((x1 >= x2) ? x1 - x2 : x1 + x2)*t1;
    cout << min(abs(x1 - x2)*t2, ans);
    return 0;
}