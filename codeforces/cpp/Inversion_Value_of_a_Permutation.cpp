#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> triangle(n);
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++){
            triangle[i - 1] = i*(i + 1)/2;
            mp[i*(i + 1)/2] = i;
        }
        k = n*(n + 1)/2 - k;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        for(int x = 0; x < n; x++){
            if(triangle[x] <= k){
                dp[triangle[x]][x + 1] = triangle[x];
            }
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int x = 0; x < n; x++){
                    if(j - triangle[x] >= 0 && i - x - 1 >= 0 && dp[j - triangle[x]][i - x - 1] != -1){
                        dp[j][i] = triangle[x];
                        break;
                    }
                }
            }
        }
        if(dp[k][n] == -1){
            cout << 0 << '\n';
            continue;
        }
        int r = k, c = n, l = 0;
        vector<int> ans, res(n);
        while(dp[r][c] != -1){
            ans.push_back(mp[dp[r][c]]);
            int tmp = dp[r][c];
            r -= tmp;
            c -= mp[tmp];
        }
        for(int i = 0; i < n; i++) res[i] = n - i;
        for(int x: ans){
            reverse(res.begin() + l, res.begin() + l + x);
            l += x;
        }
        for(int x: res) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}