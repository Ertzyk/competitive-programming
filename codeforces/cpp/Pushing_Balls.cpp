#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(string &x: grid) cin >> x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                int k = i - 1;
                while(k >= 0){
                    if(grid[k][j] == '0'){
                        break;
                    }
                    k--;
                }
                if(k == -1) continue;
                k = j - 1;
                while(k >= 0){
                    if(grid[i][k] == '0'){
                        cout << "NO\n";
                        return;
                    }
                    k--;
                }
            }
        }
    }
    cout << "YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}