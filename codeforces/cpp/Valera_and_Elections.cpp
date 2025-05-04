#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

pair<int, vector<int>> dfs(int node, int parent, const vector<vector<int>>& graph, const vector<unordered_set<int>>& problem_roads){
    int result_num = 0;
    vector<int> result_list;
    for(int neighbor: graph[node]){
        if(neighbor != parent){
            auto res = dfs(neighbor, node, graph, problem_roads);
            if(problem_roads[node].count(neighbor) && res.first == 0){
                result_num++;
                result_list.push_back(neighbor);
            } else {
                result_num += res.first;
                result_list.insert(result_list.end(), res.second.begin(), res.second.end());
            }
        }
    }
    return {result_num, result_list};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<unordered_set<int>> problem_roads(n + 1);
    for(int i = 0; i < n - 1; i++){
        int x, y, t;
        cin >> x >> y >> t;
        graph[x].push_back(y);
        graph[y].push_back(x);
        if(t == 2){
            problem_roads[x].insert(y);
            problem_roads[y].insert(x);
        }
    }
    auto result = dfs(1, 0, graph, problem_roads);
    cout << result.first << '\n';
    for(int x: result.second) cout << x << ' ';
    return 0;
}