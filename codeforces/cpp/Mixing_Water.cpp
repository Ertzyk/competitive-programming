#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll h, c, t;
        cin >> h >> c >> t;
        if(t <= (c + h)/2){
            cout << "2\n";
            continue;
        }
        ll a = ceil((double)(t - c)/(double)(2*t - c - h) - 1e-9);
        if(((t - c)*(2*a - 1) - a*(h - c))*(2*a - 3) >= (2*a - 1)*((a - 1)*(h - c) - (t - c)*(2*a - 3))){
            cout << 2*a - 3 << '\n';
        } else {
            cout << 2*a - 1 << '\n';
        }
    }
    return 0;
}