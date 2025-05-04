#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    pair<int, int> start, end;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        grid[i] = row;
        int k = row.find("S"), l = row.find("T");
        if(k != string::npos){
            start.first = i;
            start.second = k;
        }
        if(l != string::npos){
            end.first = i;
            end.second = l;
        }
    }
    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;
    q.push({{{start.first, start.second}, {0, 0}}, -1});
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[start.first][start.second] = true;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int r = front.first.first.first, c = front.first.first.second, dir_depth = front.second;
        auto last_dir = front.first.second;
        if(r == end.first && c == end.second){
            cout << "YES";
            return 0;
        }
        if(dir_depth < 2){
            for(auto dir: directions){
                if(0 <= r + dir.first && r + dir.first < n && 0 <= c + dir.second && c + dir.second < m && grid[r + dir.first][c + dir.second] != '*' && !visited[r + dir.first][c + dir.second]){
                    visited[r + dir.first][c + dir.second] = true;
                    if(last_dir != dir) q.push({{{r + dir.first, c + dir.second}, {dir.first, dir.second}}, dir_depth + 1});
                    else q.push({{{r + dir.first, c + dir.second}, {dir.first, dir.second}}, dir_depth});
                }
            }
        } else {
            if(0 <= r + last_dir.first && r + last_dir.first < n && 0 <= c + last_dir.second && c + last_dir.second < m && grid[r + last_dir.first][c + last_dir.second] != '*' && !visited[r + last_dir.first][c + last_dir.second]){
                visited[r + last_dir.first][c + last_dir.second] = true;
                q.push({{{r + last_dir.first, c + last_dir.second}, {last_dir.first, last_dir.second}}, dir_depth});
            }
        }
    }
    cout << "NO";
    return 0;
}