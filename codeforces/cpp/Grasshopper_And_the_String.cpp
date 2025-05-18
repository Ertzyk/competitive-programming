#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int result = 0, cur = 0;
    for(char ch: s){
        cur++;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y'){
            result = max(result, cur);
            cur = 0;
        }
    }
    cout << max(result, cur + 1) << '\n';
    return 0;
}