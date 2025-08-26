#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, t;
    cin >> n >> k >> t;
    cout << min(min(t, n + k - t), k) << '\n';
    return 0;
}