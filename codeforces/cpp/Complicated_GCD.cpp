#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if(a == b) cout << a << '\n';
    else cout << "1\n";
    return 0;
}