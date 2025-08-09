#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A;
    cin >> A;
    if(A == 1) cout << "1 1\n1\n";
    else cout << 2*A - 2 << " 2\n1 2\n";
    return 0;
}