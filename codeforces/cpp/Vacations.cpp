#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == 0){
            dp[i][1] = 0;
            dp[i][2] = 0;
        } else if(x == 1){
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            dp[i][2] = 0;
        } else if(x == 2){
            dp[i][1] = 0;
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
    }
    cout << n - max(max(dp[n][0], dp[n][1]), dp[n][2]);
    return 0;
}