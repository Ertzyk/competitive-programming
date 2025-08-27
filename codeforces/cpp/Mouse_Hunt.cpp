#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector<int> c(n), a(n + 1), indeg(n + 1);
    vector<bool> visited(n + 1, false);
    for(int &x: c) cin >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        indeg[a[i]]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(indeg[i] == 0) q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        indeg[a[u]]--;
        if(indeg[a[u]] == 0) q.push(a[u]);
    }
    for(int i = 1; i <= n; i++) if(!visited[i] && indeg[i] > 0){
        visited[i] = true;
        int p = a[i], cur_min = c[i - 1];
        while(p != i){
            visited[p] = true;
            cur_min = min(cur_min, c[p - 1]);
            p = a[p];
        }
        ans += cur_min;
    }
    cout << ans << '\n';
    return 0;
}