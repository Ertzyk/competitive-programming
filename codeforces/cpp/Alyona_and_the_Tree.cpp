#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, happy = 0;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<pair<int, int>>> tree(n + 1);
    for(int i = 2; i <= n; i++){
        int p, c;
        cin >> p >> c;
        tree[i].push_back({p, c});
        tree[p].push_back({i, c});
    }
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first, cur_sum = front.second;
        if(a[node - 1] >= cur_sum){
            happy++;
            for(auto child_pair: tree[node]) if(!visited[child_pair.first]){
                int child = child_pair.first, edge_weight = child_pair.second;
                visited[child] = true;
                q.push({child, max(cur_sum + edge_weight, edge_weight)});
            }
        }
    }
    cout << n - happy;
    return 0;
}