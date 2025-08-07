#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n%2 == 1) cout << n/2 << ' ' << n/2 + 1 << '\n';
    else if(n%4 == 0) cout << n/2 - 1 << ' ' << n/2 + 1 << '\n';
    else cout << n/2 - 2 << ' ' << n/2 + 2 << '\n';
    return 0;
}