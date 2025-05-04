#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int result = 0, cur = 1;
    char last_letter = 'X';
    for(int i = 0; i < s.size(); i++){
        if(s[i] == last_letter) cur++;
        else {
            result = max(result, cur);
            cur = 1;
            last_letter = s[i];
        }
    }
    cout << max(result, cur);
    return 0;
}