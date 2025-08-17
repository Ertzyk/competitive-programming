#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    vector<int> max_dist(n + 1);
    for(int i = 1; i <= n; i++) max_dist[i] = i;
    for(int col = 0; col < m; col++){
        int cur = 1;
        for(int r = 1; r < n; r++){
            if(a[r - 1][col] > a[r][col]){
                max_dist[cur] = max(r, max_dist[cur]);
                cur = r + 1;
            }
        }
        max_dist[cur] = n;
    }
    int cur_max = max_dist[1], k;
    for(int i = 2; i <= n; i++){
        if(max_dist[i] < cur_max) max_dist[i] = cur_max;
        else cur_max = max_dist[i];
    }
    cin >> k;
    while(k--){
        int l, r;
        cin >> l >> r;
        cout << ((max_dist[l] >= r) ? "Yes\n" : "No\n");
    }
    return 0;
}