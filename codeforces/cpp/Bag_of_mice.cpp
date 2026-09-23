#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, b;
    cin >> w >> b;
    vector<vector<double>> dp(w + 1, vector<double>(max(b + 1, 3), 0));
    for(int i = 1; i <= w; i++) dp[i][0] = 1;
    for(int i = 1; i <= w; i++) dp[i][1] = (double)i/(double)(i + 1);
    for(int i = 1; i <= w; i++) dp[i][2] = (double)i/(double)(i + 2) + (double)2/(double)(i + 2)/(double)(i + 1)*dp[i - 1][0];
    for(int ww = 1; ww <= w; ww++){
        for(int bb = 3; bb <= b; bb++){
            dp[ww][bb] = (double)ww/(double)(ww + bb) + (double)bb*(double)(bb - 1)*(double)(bb - 2)/(double)(bb + ww)/(double)(bb + ww - 1)/(double)(bb + ww - 2)*dp[ww][bb - 3] + (double)bb*(double)(bb - 1)*(double)ww/(double)(bb + ww)/(double)(bb + ww - 1)/(double)(bb + ww - 2)*dp[ww - 1][bb - 2];
        }
    }
    cout << fixed << setprecision(10) << dp[w][b];
    return 0;
}