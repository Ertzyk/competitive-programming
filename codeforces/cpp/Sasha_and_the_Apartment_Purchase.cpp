#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        sort(a.begin(), a.end());
        int l, r;
        if(n%2){
            l = a[n/2 - (k + 1)/2];
            r = a[n/2 + (k + 1)/2];
        } else {
            l = a[n/2 - k/2 - 1];
            r = a[n/2 + k/2];
        }
        cout << r - l + 1 << '\n';
    }
    return 0;
}