#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<set<int, greater<int>>> tree(n + 1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        tree[i].insert(p);
        tree[p].insert(i);
    }
    vector<int> subtree_size(n + 1), order, stack = {1};
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    while(!stack.empty()){
        int node = stack.back();
        stack.pop_back();
        order.push_back(node);
        for(int child: tree[node]) if(!visited[child]){
            visited[child] = true;
            stack.push_back(child);
        }
    }
    for(auto it = order.rbegin(); it != order.rend(); ++it){
        subtree_size[*it]++;
        for(int neighbor: tree[*it]){
            subtree_size[*it] += subtree_size[neighbor];
        }
    }
    while(q--){
        int u, k;
        cin >> u >> k;
        cout << ((k <= subtree_size[u]) ? order[find(order.begin(), order.end(), u) - order.begin() + k - 1] : -1) << '\n';
    }
    return 0;
}