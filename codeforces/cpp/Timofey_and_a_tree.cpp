#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    vector<int> c(n);
    unordered_set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);
    for(int &x: c) cin >> x;
    for(int i = 0; i < n - 1; i++){
        if(c[edges[i].first - 1] != c[edges[i].second - 1]){
            unordered_set<int> new_s;
            for(int x: s) if(x == edges[i].first || x == edges[i].second) new_s.insert(x);
            s = new_s;
            if(s.empty()){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n" << *s.begin();
    return 0;
}