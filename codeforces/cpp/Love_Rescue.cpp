#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    string v, t;
    cin >> v >> t;
    vector<vector<int>> graph(26);
    for(int i = 0; i < n; i++){
        graph[v[i] - 'a'].push_back(t[i] - 'a');
        graph[t[i] - 'a'].push_back(v[i] - 'a');
    }
    vector<bool> visited(26, false);
    vector<pair<int, int>> edges;
    for(int i = 0; i < 26; i++){
        if(!visited[i]){
            visited[i] = true;
            queue<int> q;
            q.push(i);
            int size = 0;
            while(!q.empty()){
                int letter = q.front();
                q.pop();
                size++;
                for(int neighbor: graph[letter]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        q.push(neighbor);
                        edges.push_back({letter, neighbor});
                    }
                }
            }
            result += size - 1;
        }
    }
    cout << result << '\n';
    for(auto p: edges) cout << (char)(p.first + 'a') << ' ' << (char)(p.second + 'a') << '\n';
    return 0;
}