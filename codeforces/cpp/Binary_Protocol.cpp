#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, ans;
    cin >> n >> s;
    int cur_digit = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cur_digit++;
        else{
            ans += (char)('0' + cur_digit);
            cur_digit = 0;
        }
    }
    ans += (char)('0' + cur_digit);
    cout << ans << '\n';
    return 0;
}