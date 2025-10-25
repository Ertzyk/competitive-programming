#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, result = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    for(int i = 0; i < n; i++){
        int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(p == 0) result = max(result, b[0] - a[i]);
        else if(p == m) result = max(result, a[i] - b[m - 1]);
        else result = max(result, min(b[p] - a[i], a[i] - b[p - 1]));
    }
    cout << result << '\n';
    return 0;
}