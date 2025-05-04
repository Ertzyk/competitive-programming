#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), positive, nonpositive;
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;
    for (int i = 0; i < n; i++) c[i] = a[i] - b[i];
    sort(c.begin(), c.end());
    int l = 0, r = n - 1;
    long long res = 0;
    while(l < r){
        if (c[l] + c[r] > 0){
            res += r - l;
            r--;
        } else {
            l ++;
        }
    }
    cout << res;
    return 0;
}