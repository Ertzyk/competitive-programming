#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, s = 0;
    cin >> n >> m >> k;
    vector<string> grid(n);
    pair<int, int> start;
    for(string &x: grid) cin >> x;
    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                start = {i, j};
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    queue<pair<int, int>> q;
    q.push(start);
    grid[start.first][start.second] = 'X';
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        s++;
        for(auto dir: directions){
            if(0 <= front.first + dir.first && front.first + dir.first < n &&
            0 <= front.second + dir.second && front.second + dir.second < m &&
            grid[front.first + dir.first][front.second + dir.second] == '.'){
                q.push({front.first + dir.first, front.second + dir.second});
                grid[front.first + dir.first][front.second + dir.second] = 'X';
            }
        }
    }
    k = s - k - 1;
    q.push(start);
    grid[start.first][start.second] = '.';
    while(!q.empty() && k > 0){
        auto front = q.front();
        q.pop();
        for(auto dir: directions){
            if(0 <= front.first + dir.first && front.first + dir.first < n &&
            0 <= front.second + dir.second && front.second + dir.second < m &&
            grid[front.first + dir.first][front.second + dir.second] == 'X'){
                q.push({front.first + dir.first, front.second + dir.second});
                grid[front.first + dir.first][front.second + dir.second] = '.';
                k--;
                if(k == 0) break;
            }
        }
    }
    for(string x: grid) cout << x << '\n';
    return 0;
}