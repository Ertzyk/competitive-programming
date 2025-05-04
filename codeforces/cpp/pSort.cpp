#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), d(n);
    for(int &x: p) cin >> x;
    for(int &x: d) cin >> x;
    vector<unordered_set<int>> graph(n);
    for(int i = 0; i < n; i++){
        if(i + d[i] < n){
            graph[i].insert(i + d[i]);
            graph[i + d[i]].insert(i);
        }
        if(i - d[i] >= 0){
            graph[i].insert(i - d[i]);
            graph[i - d[i]].insert(i);
        }
    }
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) if(!visited[i]){
        visited[i] = true;
        queue<int> q;
        q.push(i);
        unordered_set<int> elements, equivalents;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            elements.insert(node + 1);
            for(int neighbor: graph[node]) if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        for(int i: elements) equivalents.insert(p[i - 1]);
        if(elements != equivalents){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}