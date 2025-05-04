#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    char cur_min = s[0];
    cout << "Mike\n";
    for(int i = 1; i < s.size(); i++){
        if(cur_min < s[i]) cout << "Ann\n";
        else {
            cout << "Mike\n";
            cur_min = s[i];
        }
    }
    return 0;
}