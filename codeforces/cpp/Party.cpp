#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m, n, res = INT_MAX;
        cin >> n >> m;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        unordered_map<int, unordered_set<int>> graph;
        vector<pair<int, int>> edges(m);
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
            edges[i] = {x, y};
        }
        if(m%2 == 0){
            cout << 0 << '\n';
            continue;
        }
        for(auto x: graph){
            if(x.second.size()%2){
                res = min(res, a[x.first - 1]);
            }
        }
        for(auto x: edges){
            if(graph[x.first].size()%2 == 0 && graph[x.second].size()%2 == 0){
                res = min(res, a[x.first - 1] + a[x.second - 1]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}