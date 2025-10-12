#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double S, a, b, c;
    cin >> S >> a >> b >> c;
    if(a + b + c == 0){
        cout << "0 0 0\n";
    } else {
        cout << fixed << setprecision(10) << S*a/(a + b + c) << ' ' << S*b/(a + b + c) << ' ' << S*c/(a + b + c) << '\n';
    }
    return 0;
}