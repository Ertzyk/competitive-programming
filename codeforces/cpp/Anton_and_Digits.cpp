#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    cout << 256*min(min(k2, k5), k6) + 32*min(k2 - min(min(k2, k5), k6), k3) << '\n';
    return 0;
}