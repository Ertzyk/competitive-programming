#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        bool flag = true;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i <= n; i++){
            if(graph[i].size() > 2){
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        for(int i = 1; i <= n; i++){
            if(!visited.count(i)){
                int size = 0;
                visited.insert(i);
                deque<int> queue;
                queue.push_back(i);
                while(!queue.empty()){
                    int node = queue.front();
                    queue.pop_front();
                    size++;
                    for(auto x: graph[node]){
                        if(!visited.count(x)){
                            visited.insert(x);
                            queue.push_back(x);
                        }
                    }
                }
                if(size%2){
                    cout << "NO\n";
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout << "YES\n";
    }
    return 0;
}