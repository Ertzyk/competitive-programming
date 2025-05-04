#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, cyclic_components = 0, noncyclic_components = 0;
        cin >> n;
        vector<unordered_set<int>> graph(n + 1);
        for(int i = 1; i <= n; i++){
            int a;
            cin >> a;
            graph[i].insert(a);
            graph[a].insert(i);
        }
        vector<bool> visited(n + 1, false);
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                bool cyclic = true;
                visited[i] = true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    if(graph[node].size() == 1) cyclic = false;
                    for(int neighbor: graph[node]){
                        if(!visited[neighbor]){
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                cyclic ? cyclic_components++ : noncyclic_components++;
            }
        }
        cout << cyclic_components + ((noncyclic_components) ? 1 : 0) << ' ' << cyclic_components + noncyclic_components << '\n';
    }
    return 0;
}