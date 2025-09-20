#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i - 1] = {x, i};
    }
    sort(a.begin(), a.end());
    vector<bool> visited(n + 1, false);
    vector<vector<int>> result;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            vector<int> cycle;
            cycle.push_back(i);
            int p = a[i - 1].second;
            while(p != i){
                cycle.push_back(p);
                visited[p] = true;
                p = a[p - 1].second;
            }
            result.push_back(cycle);
        }
    }
    cout << result.size() << '\n';
    for(auto v: result){
        cout << v.size() << ' ';
        for(int x: v) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}