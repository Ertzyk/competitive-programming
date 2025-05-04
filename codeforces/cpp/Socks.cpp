#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, result = 0;
    cin >> n >> m >> k;
    vector<int> c(n);
    for(int &x: c) cin >> x;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        graph[l].push_back(r);
        graph[r].push_back(l);
    }
    vector<bool> visited(n + 1, false);
    for(int i = 1; i <= n; i++) if(!visited[i]){
        unordered_map<int, int> freq;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            freq[c[node - 1]]++;
            for(int neighbor: graph[node]) if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        int most_common = 0, size = 0;
        for(auto pair: freq){
            if(pair.second > most_common) most_common = pair.second;
            size += pair.second;
        }
        result += size - most_common;
    }
    cout << result;
    return 0;
}