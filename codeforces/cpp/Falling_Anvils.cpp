#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        float a, b;
        cin >> a >> b;
        if(b == 0) cout << "1\n";
        else if(4*b >= a) cout << (8*b + a)/(16*b) << '\n';
        else cout << (a - b)/a << '\n';
    }
    return 0;
}