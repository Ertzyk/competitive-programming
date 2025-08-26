#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    cout << ((a[n - 1] == a[n]) ? "NO" : "YES") << '\n';
    return 0;
}