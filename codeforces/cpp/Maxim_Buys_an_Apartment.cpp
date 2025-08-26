#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << ((k == 0 || k == n) ? '0' : '1') << ' ' << min(2*k, n - k) << '\n';
    return 0;
}