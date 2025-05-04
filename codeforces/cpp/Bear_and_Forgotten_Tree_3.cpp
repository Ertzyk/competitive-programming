#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, h, cur_len = 0;
    cin >> n >> d >> h;
    if(d > 2*h || (h == 1 && d == 1 && n > 2)){
        cout << -1;
        return 0;
    }
    vector<pair<int, int>> edges(n - 1);
    for(int i = 1; i <= h; i++){
        edges[cur_len] = {i, i + 1};
        cur_len++;
    }
    if(d > h){
        edges[cur_len] = {1, h + 2};
        cur_len++;
    }
    for(int i = h + 2; i <= d; i++){
        edges[cur_len] = {i, i + 1};
        cur_len++;
    }
    while(cur_len < n - 1){
        edges[cur_len] = {h, cur_len + 2};
        cur_len++;
    }
    for(auto p: edges) cout << p.first << ' ' << p.second << '\n';
    return 0;
}