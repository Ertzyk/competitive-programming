#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    vector<vector<int>> graph(n + 1);
    for(int i = 1; i <= n; i++){
        if(i == r1) continue;
        int p;
        cin >> p;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }
    queue<pair<int, int>> q;
    q.push({r2, 0});
    vector<int> parents(n + 1);
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first, parent = front.second;
        parents[node] = parent;
        for(int neighbor: graph[node]) if(neighbor != parent) q.push({neighbor, node});
    }
    for(int i = 1; i <= n; i++) if(i != r2) cout << parents[i] << ' ';
    return 0;
}