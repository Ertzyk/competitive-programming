#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct Position{
    int r, c, left, right;
    bool operator<(const Position& other) const {
        if(left != other.left) return left < other.left;
        return right < other.right;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, r, c, result = 0;
    Position start;
    cin >> n >> m >> r >> c >> start.left >> start.right;
    start.r = r - 1;
    start.c = c - 1;
    vector<string> grid(n);
    const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(string &x: grid) cin >> x;
    priority_queue<Position> mx_heap;
    mx_heap.push(start);
    grid[r - 1][c - 1] = '+';
    while(!mx_heap.empty()){
        Position cur = mx_heap.top();
        mx_heap.pop();
        result++;
        for(auto [dir_r, dir_c]: directions){
            if(cur.r + dir_r >= 0 && cur.c + dir_c >= 0 && cur.r + dir_r < n && cur.c + dir_c < m && grid[cur.r + dir_r][cur.c + dir_c] == '.'){
                if(dir_c == -1 && cur.left == 0) continue;
                if(dir_c == 1 && cur.right == 0) continue;
                Position p;
                p.r = cur.r + dir_r;
                p.c = cur.c + dir_c;
                p.left = ((dir_c == -1) ? cur.left - 1 : cur.left);
                p.right = ((dir_c == 1) ? cur.right - 1 : cur.right);
                grid[p.r][p.c] = '+';
                mx_heap.push(p);
            }
        }
    }
    cout << result << '\n';
    return 0;
}