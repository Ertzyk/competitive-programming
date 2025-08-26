#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int i = 0; i < n; i++) c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    int ans = accumulate(b.begin(), b.end(), 0);
    for(int i = 0; i < n; i++){
        if(i >= k && c[i] >= 0) break;
        ans += c[i];
    }
    cout << ans << '\n';
    return 0;
}