#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    char s, e;
    int n, a, b;
    cin >> s >> e >> n;
    if(s == '^') a = 0;
    else if(s == '>') a = 1;
    else if(s == 'v') a = 2;
    else a = 3;
    if(e == '^') b = 0;
    else if(e == '>') b = 1;
    else if(e == 'v') b = 2;
    else b = 3;
    if(n%4 == 0 || n%4 == 2) cout << "undefined\n";
    else if((b - a + 4)%4 == n%4) cout << "cw\n";
    else cout << "ccw\n";
    return 0;
}