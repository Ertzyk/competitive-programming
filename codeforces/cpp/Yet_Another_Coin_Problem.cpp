#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> dp(71, 71);
    dp[0] = 0;
    for(int i = 1; i < 71; i++){
        for(int j = 1; j <= 5; j++){
            if(i < j*(j + 1)/2) continue;
            dp[i] = min(dp[i], dp[i - j*(j + 1)/2] + 1);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 71) cout << dp[n];
        else cout << (n - 56)/15 + dp[(n - 56)%15 + 56];
        cout << '\n';
    }
    return 0;
}