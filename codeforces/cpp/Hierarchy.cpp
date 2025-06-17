#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, count_empty = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
    }
    cin >> m;
    vector<int> cheapest_parent(n + 1, -1);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(cheapest_parent[b] == -1) cheapest_parent[b] = c;
        else cheapest_parent[b] = min(cheapest_parent[b], c);
    }
    for(int i = 1; i <= n; i++) if(cheapest_parent[i] == -1) count_empty++;
    if(count_empty > 1) cout << "-1\n";
    else cout << accumulate(cheapest_parent.begin(), cheapest_parent.end(), 0) + 2 << '\n';
    return 0;
}