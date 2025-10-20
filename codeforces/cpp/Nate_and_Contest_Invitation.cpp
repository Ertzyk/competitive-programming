#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> visited;
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> components_size;
    for(int i = 0; i < n - graph.size(); i++) components_size.push_back(1);
    for(auto pr: graph){
        if(!visited[pr.first]){
            visited[pr.first] = true;
            queue<string> q;
            q.push(pr.first);
            int len = 0;
            while(!q.empty()){
                string node = q.front();
                q.pop();
                len++;
                for(string nei: graph[node]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
            components_size.push_back(len);
        }
    }
    sort(components_size.rbegin(), components_size.rend());
    cout << accumulate(components_size.begin(), components_size.begin() + min(k, (int)components_size.size()), 0) << '\n';
    return 0;
}