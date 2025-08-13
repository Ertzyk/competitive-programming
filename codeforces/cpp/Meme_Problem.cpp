#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        if(d > 0 && d < 4) cout << "N\n"; 
        else cout << fixed << setprecision(10) << "Y " << (d + sqrt(d*d - 4*d))/2 << ' ' << (d - sqrt(d*d - 4*d))/2 << '\n';
    }
    return 0;
}