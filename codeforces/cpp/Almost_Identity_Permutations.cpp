#include <iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    if(k == 1) cout << 1;
    else if (k == 2) cout << n*(n - 1)/2 + 1;
    else if (k == 3) cout << n*(n - 1)*(n - 2)/3 + n*(n - 1)/2 + 1;
    else cout << 3*n*(n - 1)*(n - 2)*(n - 3)/8 + n*(n - 1)*(n - 2)/3 + n*(n - 1)/2 + 1;
    return 0;
}