#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n), d(n);
        for(int &x: p) cin >> x;
        for(int &x: d) cin >> x;
        vector<bool> visited(n + 1, false);
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(visited[d[i]]) {
                cout << cur << ' ';
                continue;
            }
            int a = d[i];
            while(!visited[a] && p[a - 1] != a){
                visited[a] = true;
                a = p[a - 1];
                cur++;
            }
            if(!visited[a]){
                visited[a] = true;
                cur++;
            }
            cout << cur << ' ';
        }
        cout << '\n';
    }
    return 0;
}