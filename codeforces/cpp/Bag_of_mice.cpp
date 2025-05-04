#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, b;
    cin >> w >> b;
    vector<vector<double>> dp(w + 1, vector<double>(b + 1, 0));
    for(int i = 1; i <= w; i++) dp[i][0] = 1;
    for(double i = 1; i <= w; i++) dp[i][1] = i/(i + (double)1);
    dp[1][2] = (double)1/(double)3;
    for(double i = 2; i <= w; i++) dp[i][2] = (i*i + i + (double)2)/(i + (double)1)/(i + (double)2);
    for(double ww = 1; ww <= w; ww++){
        for(double bb = 3; bb <= b; bb++){
            dp[ww][bb] = ww/(ww + bb) + bb*(bb - (double)1)*(bb - (double)2)/(bb + ww)/(bb + ww - (double)1)/(bb + ww - (double)2)*dp[bb - 3][ww] + b*(b - (double)1)*w/(bb + ww)/(bb + ww - (double)1)/(bb + ww - (double)2)*dp[bb - 2][ww - 1];
        }
    }
    for(int i = 0; i <= w; i++){
        for(int j = 0; j <= b; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[w][b];
    return 0;
}