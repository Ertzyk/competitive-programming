#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y, a;
        cin >> x >> y >> a;
        a %= x + y;
        if(x > a) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}