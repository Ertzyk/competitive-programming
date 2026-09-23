#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        bool yes = false;
        if(a >= b && a >= c){
            if(a == b + c) yes = true;
        } else if(b >= a && b >= c){
            if(b == a + c) yes = true;
        } else {
            if(c == a + b) yes = true;
        }
        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}