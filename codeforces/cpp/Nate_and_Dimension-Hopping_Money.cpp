#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, x, y;
    cin >> n >> x >> y;
    x = 100 - x;
    y = 100 - y;
    double p = n/(1 - x/100 + x*y/10000);
    cout << fixed << setprecision(10) << n << ' ' << p << ' ' << p*x/100 << ' ' << p*x*y/10000 << ' ' << p*x*y/10000 << '\n';
    return 0;
}