#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> graph(n + 1);
    unordered_set<int> seen;
    for(int i = 1; i <= d; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        seen.insert(x);
        seen.insert(y);
        vector<bool> visited(n + 1, false);
        priority_queue<int, vector<int>, greater<int>> sizes;
        for(int j = 1; j <= n; j++) if(!visited[j]){
            visited[j] = true;
            queue<int> q;
            q.push(j);
            int size = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                size++;
                for(int neighbor: graph[node]) if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
            sizes.push(size);
            if(sizes.size() > max(i - (int)seen.size() + 2, 1)) sizes.pop();
        }
        int sum = -1;
        while(!sizes.empty()){
            sum += sizes.top();
            sizes.pop();
        }
        cout << sum << '\n';
    }
    return 0;
}