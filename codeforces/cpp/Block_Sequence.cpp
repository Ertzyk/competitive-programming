#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), dp(n + 1, 0);
        for(int &x: a) cin >> x;
        for(int i = n - 1; i >= 0; i--){
            if(i + a[i] >= n) dp[i] = dp[i + 1] + 1;
            else dp[i] = min(dp[i + a[i] + 1], dp[i + 1] + 1);
        }
        cout << dp[0] << '\n';
    }
    return 0;
}