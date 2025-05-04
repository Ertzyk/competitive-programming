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
        bool is01 = false;
        int result = 1;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] != s[i + 1]){
                result++;
                if(s[i] == '0') is01 = true;
            }
        }
        if(is01) result--;
        cout << result << '\n';
    }
    return 0;
}