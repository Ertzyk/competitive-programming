#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    if(n <= 6){
        cout << m << '\n';
        return 0;
    }
    int result = 0;
    for(int i = 1; i < 7; i++){
        for(int j = i + 1; j <= 7; j++){
            int cur_res = 0;
            for(int k = 1; k <= 7; k++){
                if(k == i || k == j) continue;
                cur_res += graph[k].size();
                if(graph[k].count(i)) cur_res--;
                if(graph[k].count(j)) cur_res--;
            }
            cur_res /= 2;
            vector<int> union_res;
            set_union(graph[i].begin(), graph[i].end(), graph[j].begin(), graph[j].end(), back_inserter(union_res));
            cur_res += union_res.size();
            if(graph[i].count(j)) cur_res--;
            result = max(result, cur_res);
        }
    }
    cout << result << '\n';
    return 0;
}