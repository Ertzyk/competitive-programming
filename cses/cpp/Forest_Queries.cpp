#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> forest(n, vector<ll>(n, 0)), twoD_pref_sum(n + 1, vector<ll>(n + 1, 0));
    for(ll i = 0; i < n*n; i++){
        char ch;
        cin >> ch;
        forest[i/n][i%n] = (ll)(ch == '*');
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            twoD_pref_sum[i][j] = forest[i - 1][j - 1] + twoD_pref_sum[i - 1][j] + twoD_pref_sum[i][j - 1] - twoD_pref_sum[i - 1][j - 1];
        }
    }
    while(q--){
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << twoD_pref_sum[y2][x2] - twoD_pref_sum[y1 - 1][x2] - twoD_pref_sum[y2][x1 - 1] + twoD_pref_sum[y1 - 1][x1 - 1] << '\n'; 
    }
    return 0;
}