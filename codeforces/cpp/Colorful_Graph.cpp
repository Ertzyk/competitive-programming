#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for(int &x: c) cin >> x;
    unordered_map<int, unordered_set<int>> graph;
    set<int> keys(c.begin(), c.end());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(c[a - 1] != c[b - 1]){
            graph[c[a - 1]].insert(c[b - 1]);
            graph[c[b - 1]].insert(c[a - 1]);
        }
    }
    int max_size = -1, max_color = -1;
    for(int x: keys){
        if((int)graph[x].size() > max_size){
            max_size = graph[x].size();
            max_color = x;
        }
    }
    cout << max_color;
    return 0;
}