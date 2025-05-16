#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int result = 0;
    char prev = 'a';
    for(char ch: s){
        result += min(abs(prev - ch), 26 - abs(prev - ch));
        prev = ch;
    }
    cout << result << '\n';
    return 0;
}