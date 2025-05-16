#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, 0));
    for(int i = 1; i <= h; i++) dp[0][i] = 1;
    for(int i = 2; i <= h; i++) dp[1][i] = 1;
    for(int hcur = 3; hcur <= h; hcur++){
        for(int ncur = 2; ncur <= n; ncur++){
            for(int i = 0; i < ncur; i++){
                dp[ncur][hcur] += dp[i][hcur - 1]*dp[ncur - i - 1][hcur - 1];
            }
        }
    }
    vector<ll> C(n + 1, 0);
    C[0] = C[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i - 1; j++){
            C[i] += C[j]*C[i - 1 - j];
        }
    }
    cout << C[n] - dp[n][h] << '\n';
    return 0;
}