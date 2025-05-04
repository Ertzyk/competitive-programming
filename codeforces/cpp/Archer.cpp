#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(10) << (a/b)/(1 - (1 - a/b)*(1 - c/d));
    return 0;
}