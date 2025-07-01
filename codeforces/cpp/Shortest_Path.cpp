#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n + 1);
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    vector<unordered_set<int>> forbidden_pairs(n + 1);
    vector<vector<pair<int, int>>> previous(n + 1, vector<pair<int, int>>(n + 1));
    vector<int> result;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 0; i < k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        forbidden_pairs[b].insert(3001*a + c);
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()){
        auto front = q.front();
        int node = front.first, prev = front.second;
        q.pop();
        if(node == n){
            result.push_back(n);
            while(node != 1){
                auto p = previous[node][prev];
                node = p.first;
                prev = p.second;
                result.push_back(node);
            }
            reverse(result.begin(), result.end());
            cout << result.size() - 1 << '\n';
            for(int x: result) cout << x << ' ';
            cout << '\n';
            return 0;
        }
        for(auto neighbor: graph[node]){
            if(!visited[neighbor][node] && !forbidden_pairs[node].count(prev*3001 + neighbor)){
                visited[neighbor][node] = true;
                q.push({neighbor, node});
                previous[neighbor][node] = {node, prev};
            }
        }
    }
    cout << "-1\n";
    return 0;
}