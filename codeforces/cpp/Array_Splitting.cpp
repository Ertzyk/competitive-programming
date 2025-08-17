#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), diff;
    diff.reserve(n - 1);
    for(int &x: a) cin >> x;
    int ans = a[n - 1] -  a[0];
    for(int i = 0; i < n - 1; i++) diff.push_back(a[i + 1] - a[i]);
    sort(diff.rbegin(), diff.rend());
    for(int i = 0; i < k - 1; i++) ans -= diff[i];
    cout << ans << '\n';
    return 0;
}