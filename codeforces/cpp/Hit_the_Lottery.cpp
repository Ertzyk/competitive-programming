#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(100, 100), coins = {1, 5, 10, 20, 100};
    dp[0] = 0;
    for(int i = 1; i < 100; i++) for(int coin : coins) if(i - coin >= 0) dp[i] = min(dp[i], dp[i - coin] + 1);
    cout << n/100 + dp[n%100] << '\n';
    return 0;   
}