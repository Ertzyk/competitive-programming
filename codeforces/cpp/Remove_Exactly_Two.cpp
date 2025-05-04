#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<unordered_set<int>> graph(n + 1);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            graph[u].insert(v);
            graph[v].insert(u);
        }
        vector<vector<int>> bucket(n);
        for(int i = 1; i <= n; i++) bucket[graph[i].size()].push_back(i);
        int pointer = n - 1;
        while(bucket[pointer].empty()) pointer--;
        if(bucket[pointer].size() >= 3) cout << 2*pointer - 1 << '\n';
        else if(bucket[pointer].size() == 2) cout << 2*pointer - 1 - ((graph[bucket[pointer][0]].count(bucket[pointer][1])) ? 1 : 0) << '\n';
        else{
            int mem = pointer;
            do pointer--; while(bucket[pointer].empty());
            bool found = true;
            for(int node: bucket[pointer]) if(!graph[node].count(bucket[mem][0])){
                cout << pointer + mem - 1 << '\n';
                found = false;
                break;
            }
            if(found) cout << pointer + mem - 2 << '\n';
        }
    }
    return 0;
}