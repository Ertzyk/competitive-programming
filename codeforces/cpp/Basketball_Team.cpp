#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, h, s = 0, sh;
    cin >> n >> m >> h;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        s += x;
        if(i == h) sh = x;
    }
    if(n > s){
        cout << -1;
        return 0;
    }
    if(s - sh < n - 1){
        cout << 1;
        return 0;
    }
    double result = 1;
    for(int i = 1; i < n; i++){
        result *= s - sh - n + 1 + i;
        result /= s - n + i;
    }
    cout << fixed << setprecision(8) << 1 - result;
    return 0;
}