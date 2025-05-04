#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for(int &x: b) cin >> x;
    int pa = 0, pb = 0, result = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(pa < n && pb < m){
        if(abs(a[pa] - b[pb]) <= 1){
            result++;
            pa++;
            pb++;
        } else if(a[pa] > b[pb]){
            pb++;
        } else {
            pa++;
        }
    }
    cout << result;
    return 0;
}