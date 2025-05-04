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
        int result = 0;
        if(s.size() == 1){
            cout << "0\n";
            continue;
        }
        if(s[1] == s[0]){
            result++;
            s[1] = '-';
        }
        for(int i = 2; i < s.size(); i++){
            if(s[i] == s[i - 2] || s[i] == s[i - 1]){
                result++;
                s[i] = '-';
            }
        }
        cout << result << '\n';
    }
    return 0;
}