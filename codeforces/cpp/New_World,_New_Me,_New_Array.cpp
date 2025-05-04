#include <iostream>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        float n, k, p;
        cin >> n >> k >> p;
        if(k < 0) k = -k;
        if(k > n*p) cout << -1 << '\n';
        else cout << ceil(k/p) << '\n';
    }
    return 0;
}