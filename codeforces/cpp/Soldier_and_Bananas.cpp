#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, n, w;
    cin >> k >> n >> w;
    cout << max(0, k*w*(w + 1)/2 - n);
    return 0;
}