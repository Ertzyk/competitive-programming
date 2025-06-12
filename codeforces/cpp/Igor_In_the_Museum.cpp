#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for(string &s: grid) cin >> s;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> result(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(grid[i][j] == '.'){
                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                int counter = 0;
                while(!q.empty()){
                    auto front = q.front();
                    int r = front.first, c = front.second;
                    q.pop();
                    for(auto p: directions){
                        if(!visited[r + p.first][c + p.second]){
                            if(grid[r + p.first][c + p.second] == '*') counter++;
                            else{
                                visited[r + p.first][c + p.second] = true;
                                q.push({r + p.first, c + p.second});
                            }
                        }
                    }
                }
                q.push({i, j});
                grid[i][j] = '*';
                while(!q.empty()){
                    auto front = q.front();
                    int r = front.first, c = front.second;
                    result[r][c] = counter;
                    q.pop();
                    for(auto p: directions){
                        if(grid[r + p.first][c + p.second] == '.'){
                            grid[r + p.first][c + p.second] = '*';
                            q.push({r + p.first, c + p.second});
                        }
                    }
                }
            }
        }
    }
    while(k--){
        int x, y;
        cin >> x >> y;
        cout << result[x - 1][y - 1] << '\n';
    }
    return 0;
}