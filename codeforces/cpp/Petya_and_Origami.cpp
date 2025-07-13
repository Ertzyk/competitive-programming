#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    cout << (2*n - 1)/k + (5*n - 1)/k + (8*n - 1)/k + 3;
    return 0;
}