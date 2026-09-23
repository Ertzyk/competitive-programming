#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> grid(n, vector<ll>(m)), dpm(n, vector<ll>(m)), dpM(n, vector<ll>(m));
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        if((n + m)%2 == 0){
            cout << "NO\n";
            continue;
        }
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dpm[0][0] = grid[0][0];
                    dpM[0][0] = grid[0][0];
                } else if(i == 0){
                    dpm[0][j] = dpm[0][j - 1] + grid[0][j];
                    dpM[0][j] = dpm[0][j];
                } else if(j == 0){
                    dpm[i][0] = dpm[i - 1][0] + grid[i][0];
                    dpM[i][0] = dpm[i][0];
                } else {
                    dpm[i][j] = min(dpm[i - 1][j], dpm[i][j - 1]) + grid[i][j];
                    dpM[i][j] = max(dpM[i - 1][j], dpM[i][j - 1]) + grid[i][j];
                }
            }
        }
        if(dpm[n - 1][m - 1]*dpM[n - 1][m - 1] <= 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}