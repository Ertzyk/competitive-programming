#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> main_courses(k);
    for(int &x: main_courses) cin >> x;
    vector<vector<int>> graph(n + 1), reverse_graph(n + 1);
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        while(t--){
            int x;
            cin >> x;
            graph[i].push_back(x);
            reverse_graph[x].push_back(i);
        }
    }
    return 0;
}