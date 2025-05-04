#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> dp(s.size() + 1), max_last_letter(26, -1);
        dp[0] = 0;
        for(int i = 0; i < s.size(); i++){
            if(max_last_letter[s[i] - 'a'] == -1) dp[i + 1] = dp[i] + 1;
            else dp[i + 1] = min(dp[i] + 1, dp[max_last_letter[s[i] - 'a']] + i - max_last_letter[s[i] - 'a'] - 1);
            max_last_letter[s[i] - 'a'] = i;
        }
        cout << dp.back() << '\n';
    }
    return 0;
}