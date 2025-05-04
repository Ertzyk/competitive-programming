#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

vector<int> divisors(int a){
    vector<int> result;
    for(int i = 1; i*i <= a; i++){
        if(a%i == 0){
            result.push_back(i);
            if(i*i != a) result.push_back(a/i);
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, s = 0;
    cin >> n >> k;
    if(k == 1){
        cout << n;
        return 0;
    }
    vector<vector<int>> precal_div(n + 1);
    for(int i = 1; i <= n; i++) precal_div[i] = divisors(i);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; i++) dp[i][1] = 1;
    for(int i = 2; i < k; i++){
        for(int j = 1; j <= n; j++){
            for(int d: precal_div[j]){
                dp[j][i] += dp[d][i - 1];
                dp[j][i] %= MOD;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int d: precal_div[i]){
            s += dp[d][k - 1];
            s %= MOD;
        }
    }
    cout << s;
    return 0;
}