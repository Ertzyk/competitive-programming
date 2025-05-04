#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, r;
    cin >> a >> b >> r;
    cout << ((a >= 2*r && b >= 2*r) ? "First" : "Second");
    return 0;
}