#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> sets(n + m + 1);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            sets[i].insert(j);
        }
    }
    for(int i = n + 1; i <= n + m; i++){
        int operation;
        cin >> operation;
        if(operation == 1){
            int a, b;
            cin >> a >> b;
            set_union(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), inserter(sets[i], sets[i].begin()));
        } else if(operation == 2){
            int a, b;
            cin >> a >> b;
            set_intersection(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), inserter(sets[i], sets[i].begin()));
        } else {
            int a;
            cin >> a;
            set_difference(sets[1].begin(), sets[1].end(), sets[a].begin(), sets[a].end(), inserter(sets[i], sets[i].begin()));
        }
    }
    while(q--){
        int x, v;
        cin >> x >> v;
        cout << ((sets[x].count(v)) ? "TAK\n" : "NIE\n");
    }
    return 0;
}