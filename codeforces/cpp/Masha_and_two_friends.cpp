#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, m, x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll xs = max(x1, x3), ys = max(y1, y3), xe = min(x2, x4), ye = min(y2, y4);
        ll w = (n*m + 1)/2 + (x2 - x1 + 1)*(y2 - y1 + 1)/2 - (x4 - x3 + 1)*(y4 - y3 + 1)/2;
        if(((x2 - x1 + 1)*(y2 - y1 + 1)%2 == 1) && ((x1 + y1)%2 == 1)) w++;
        if(((x4 - x3 + 1)*(y4 - y3 + 1)%2 == 1) && ((x3 + y3)%2 == 0)) w--;
        if(xs <= xe && ys <= ye){
            w -= (xe - xs + 1)*(ye - ys + 1)/2;
            if((xe - xs + 1)*(ye - ys + 1)%2 && (xs + ys)%2) w--;
        }
        cout << w << ' ' << n*m - w << '\n';
    }
    return 0;
}