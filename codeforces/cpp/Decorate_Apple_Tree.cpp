#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }
    if(n == 1){
        cout << "1\n";
        return 0;
    }
    vector<int> count_leaves(n + 1, 0), order;
    vector<bool> visited(n + 1, false);
    queue<int> q;
    order.reserve(n);
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        order.push_back(node);
        for(int neighbor: tree[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    reverse(order.begin(), order.end());
    for(int x: order){
        if(tree[x].size() == 1 && x != 1) count_leaves[x] = 1;
        else {
            for(int child: tree[x]) count_leaves[x] += count_leaves[child];
        }
    }
    sort(count_leaves.begin(), count_leaves.end());
    for(int i = 1; i <= n; i++) cout << count_leaves[i] << " \n"[i == n];
    return 0;
}