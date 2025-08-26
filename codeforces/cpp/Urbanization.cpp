#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double n1, n2, ans = 0;
    cin >> n >> n1 >> n2;
    vector<double> a(n);
    for(double &x : a) cin >> x;
    if(n2 < n1) swap(n1, n2);
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < n1; i++) ans += a[i]/n1;
    for(int i = n1; i < n1 + n2; i++) ans += a[i]/n2;
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}