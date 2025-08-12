#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << n/2*2 + (n + 1)/2 << '\n';
    for(int i = 2; i <= n; i += 2) cout << i << ' ';
    for(int i = 1; i <= n; i += 2) cout << i << ' ';
    for(int i = 2; i <= n; i += 2) cout << i << " \n"[i == n - 1 || i == n];
    return 0;
}