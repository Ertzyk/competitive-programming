#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << 2*n - 3 << '\n';
        for(int i = 2; i <= n; i++) cout << i << ' ' << 1 << ' ' << i << '\n';
        for(int i = 1; i <= n - 2; i++) cout << i << ' ' << i + 1 << ' ' << n << '\n';
    }
    return 0;
}