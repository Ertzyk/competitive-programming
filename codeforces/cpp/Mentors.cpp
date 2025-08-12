#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, repeat = 0;
    cin >> n >> k;
    vector<pair<int, int>> r_sorted(n);
    vector<int> result(n, 0), r(n, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        r[i] = x;
        r_sorted[i] = {x, i};
    }
    sort(r_sorted.begin(), r_sorted.end());
    for(int i = 1; i < n; i++){
        if(r_sorted[i].first == r_sorted[i - 1].first) repeat++;
        else repeat = 0;
        result[r_sorted[i].second] = i - repeat;
    }
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        if(r[x - 1] < r[y - 1]) result[y - 1]--;
        else if(r[x - 1] > r[y - 1]) result[x - 1]--;
    }
    for(int x: result) cout << x << ' ';
    cout << '\n';
    return 0;
}