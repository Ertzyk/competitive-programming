#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &x: p) cin >> x;
    vector<vector<int>> graph(n + 1), component_elements;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) if(s[j] == '1') graph[i].push_back(j);
    }
    unordered_set<int> visited;
    vector<int> component(n), result(n);
    int type = 0;
    for(int i = 0; i < n; i++){
        if(!visited.count(i)){
            vector<int> res;
            visited.insert(i);
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                component[node] = type;
                res.push_back(p[node]);
                for(int neighbor: graph[node]){
                    if(!visited.count(neighbor)){
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            type++;
            sort(res.rbegin(), res.rend());
            component_elements.push_back(res);
        }
    }
    for(int i = 0; i < n; i++){
        result[i] = component_elements[component[i]].back();
        component_elements[component[i]].pop_back();
    }
    for(int x: result) cout << x << ' ';
    return 0;
}