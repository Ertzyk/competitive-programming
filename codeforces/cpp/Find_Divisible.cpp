#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int l, r;
        cin >> l >> r;
        cout << l << ' ' << 2*l << '\n';
    }
    return 0;
}