#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]){
            if((s[i - 1] == 'a') || (i < s.size() - 1) && (s[i + 1] == 'a')){
                if((s[i - 1] == 'b') || (i < s.size() - 1) && (s[i + 1] == 'b')) s[i] = 'c';
                else s[i] = 'b';
            } else s[i] = 'a';
            i++;
        }
    }
    cout << s;
    return 0;
}