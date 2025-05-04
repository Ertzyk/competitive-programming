#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.find("it") != string::npos) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}