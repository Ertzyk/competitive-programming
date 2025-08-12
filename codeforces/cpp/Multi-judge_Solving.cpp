#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p = 0, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    while(p < n){
        if(a[p] <= 2*k){
            k = max(k, a[p]);
            p++;
        } else {
            ans++;
            k *= 2;
        }
    }
    cout << ans << '\n';
    return 0;
}