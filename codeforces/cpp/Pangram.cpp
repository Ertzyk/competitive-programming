#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<bool> appeared(26, false);
    for(int i = 0; i < n; i++) appeared[tolower((s[i])) - 'a'] = true;
    for(bool b : appeared){
        if(!b){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}