#include <iostream>
#include <vector>
using namespace std;

int find_comb(int cur_sum, int cur_min, int cur_max, int cur_count, int point, const vector<int>& c, const int& l, const int& r, const int& x, const int& n){
    if(point == n) return ((cur_sum >= l && cur_sum <= r && cur_max - cur_min >= x && cur_count >= 2) ? 1 : 0);
    return find_comb(cur_sum, cur_min, cur_max, cur_count, point + 1, c, l, r, x, n) +
    find_comb(cur_sum + c[point], min(cur_min, c[point]), max(cur_max, c[point]), cur_count + 1, point + 1, c, l, r, x, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> c(n);
    for(int &p: c) cin >> p;
    cout << find_comb(0, INT_MAX, 0, 0, 0, c, l, r, x, n);
    return 0;
}