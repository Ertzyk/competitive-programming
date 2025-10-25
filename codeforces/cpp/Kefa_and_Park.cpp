#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int val, parent, cats;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, result = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<vector<int>> graph(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Node start;
    start.val = 1;
    start.parent = 0;
    start.cats = 0;
    queue<Node> q;
    q.push(start);
    while(!q.empty()){
        Node node = q.front();
        q.pop();
        if(a[node.val - 1] == 1) node.cats++;
        else node.cats = 0;
        if(node.cats > m) continue;
        bool child = true;
        for(int neighbor: graph[node.val]){
            if(neighbor != node.parent){
                child = false;
                Node new_node;
                new_node.val = neighbor;
                new_node.parent = node.val;
                new_node.cats = node.cats;
                q.push(new_node);
            }
        }
        if(child) result++;
    }
    cout << result << '\n';
    return 0;
}