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
        ll n, q;
        cin >> n >> q;
        vector<vector<ll>> grid(1001, vector<ll>(1001, 0)), twoD_prefix_sum(1001, vector<ll>(1001, 0));
        while(n--){
            ll h, w;
            cin >> h >> w;
            grid[h][w] += h*w;
        }
        for(ll i = 1; i <= 1000; i++){
            for(ll j = 1; j <= 1000; j++){
                twoD_prefix_sum[i][j] = grid[i][j] + twoD_prefix_sum[i - 1][j] + twoD_prefix_sum[i][j - 1] - twoD_prefix_sum[i - 1][j - 1];
            }
        }
        while(q--){
            ll hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            cout << twoD_prefix_sum[hb - 1][wb - 1] - twoD_prefix_sum[hb - 1][ws] - twoD_prefix_sum[hs][wb - 1] + twoD_prefix_sum[hs][ws] << '\n';
        }
    }
    return 0;
}