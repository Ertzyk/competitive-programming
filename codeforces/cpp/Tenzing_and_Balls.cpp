#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), dp(n + 1, 0), min_per_color(n + 1, INT_MAX);
        for(int &x: a) cin >> x;
        for(int i = 1; i <= n; i++){
            dp[i] = min(dp[i - 1] + 1, min_per_color[a[i - 1]]);
            min_per_color[a[i - 1]] = min(min_per_color[a[i - 1]], dp[i - 1]);
        }
        cout << n - dp[n] << '\n';
    }
    return 0;
}