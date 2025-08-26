#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
    for(int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(grid[i][j] != 1){
        bool good = false;
        for(int s = 0; s < n; s++){
            for(int t = 0; t < n; t++) if(grid[i][j] == grid[i][t] + grid[s][j]){
                good = true;
                break;
            }
            if(good) break;
        }
        if(!good){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}