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
    for(string &x: grid) cin >> x;
    vector<bool> visited(n*m, false);
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int r = 1; r < n - 1; r++){
        for(int c = 1; c < m - 1; c++){
            if(grid[r][c] == '.' && !visited[r*m + c]){
                visited[r*m + c] = true;
                queue<pair<int, int>> q;
                q.push({r, c});
                bool lake = true;
                int size = 0;
                while(!q.empty()){
                    auto front = q.front();
                    q.pop();
                    int node_r = front.first, node_c = front.second;
                    if(node_r == 0 || node_r == n - 1 || node_c == 0 || node_c == m - 1) lake = false;
                    size++;
                    for(auto p: directions){
                        if(0 <= node_r + p.first && node_r + p.first < n && 0 <= node_c + p.second && node_c + p.second < m){
                            if(!visited[(node_r + p.first)*m + node_c + p.second] && grid[node_r + p.first][node_c + p.second] == '.'){
                                visited[(node_r + p.first)*m + node_c + p.second] = true;
                                q.push({node_r + p.first, node_c + p.second});
                            }
                        }
                    }
                }
                if(lake) pq.push({size, r, c});
            }
        }
    }
    int result = 0;
    while(pq.size() > k){
        auto front = pq.top();
        pq.pop();
        queue<pair<int, int>> q;
        result += front[0];
        q.push({front[1], front[2]});
        grid[front[1]][front[2]] = '*';
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int node_r = front.first, node_c = front.second;
            for(auto p: directions){
                if(0 <= node_r + p.first && node_r + p.first < n && 0 <= node_c + p.second && node_c + p.second < m){
                    if(grid[node_r + p.first][node_c + p.second] == '.'){
                        grid[node_r + p.first][node_c + p.second] = '*';
                        q.push({node_r + p.first, node_c + p.second});
                    }
                }
            }
        }
    }
    cout << result << '\n';
    for(string s: grid) cout << s << '\n';
    return 0;
}