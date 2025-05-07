#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string n;
    cin >> n;
    int lucky_digits = 0;
    for(char ch: n) if(ch == '4' || ch == '7') lucky_digits++;
    string str_ld = to_string(lucky_digits);
    bool lucky = true;
    for(char ch: str_ld) if(ch != '4' && ch != '7') lucky = false;
    cout << ((lucky) ? "YES\n" : "NO\n");
    return 0;
}