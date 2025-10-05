#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, M;
    cin >> n >> k >> M;
    vector<int> t(k);
    for(int &x: t) cin >> x;
    sort(t.begin(), t.end());
    int sumt = accumulate(t.begin(), t.end(), 0), result = 0;
    for(int full = 0; full <= n; full++){
        int cur_points = full*(k + 1), cur_minutes = M;
        cur_minutes -= sumt*full;
        if(cur_minutes < 0) break;
        for(int i = 0; i < k; i++){
            if((n - full)*t[i] <= cur_minutes){
                cur_minutes -= (n - full)*t[i];
                cur_points += n - full;
            } else {
                cur_points += cur_minutes/t[i];
                break;
            }
        }
        result = max(result, cur_points);
    }
    cout << result << '\n';
    return 0;
}