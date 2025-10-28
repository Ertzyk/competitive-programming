#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == b && b == c && c == d) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}