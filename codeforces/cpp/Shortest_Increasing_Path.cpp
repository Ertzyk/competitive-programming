#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(y > x) cout << "2\n";
        else if(x == y || x == y + 1 || y == 1) cout << "-1\n";
        else cout << "3\n";
    }
    return 0;
}