#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> stage(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> stage[i][j];
    for(int i = 0; i < n; i++){
        int count_ones = 0, first_one = -1, last_one = -1;
        for(int j = 0; j < m; j++){
            if(stage[i][j] == 1){
                count_ones++;
                if(first_one == -1) first_one = j;
                last_one = j;
            }
        }
        if(count_ones == 1) ans += m - 1;
        else if(count_ones > 1) ans += m - 2*count_ones + last_one - first_one + 1;
    }
    for(int i = 0; i < m; i++){
        int count_ones = 0, first_one = -1, last_one = -1;
        for(int j = 0; j < n; j++){
            if(stage[j][i] == 1){
                count_ones++;
                if(first_one == -1) first_one = j;
                last_one = j;
            }
        }
        if(count_ones == 1) ans += n - 1;
        else if(count_ones > 1) ans += n - 2*count_ones + last_one - first_one + 1;
    }
    cout << ans << '\n';
    return 0;
}